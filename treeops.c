#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "account.h"
#include "treeops.h"

void print_all_items(node_t *node, void print(void *)){
    if (node) {
        print_all_items(node->left, print);
        print_all_items(node->right, print);
        print(node->data);
    }
    return;
}

node_t *node_init(void *data){
    node_t *new = (node_t *)malloc(sizeof(node_t));
    assert(new);
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

tree_t *tree_init(int cmp(void*, void*), void print(void*)){
    tree_t *new_tree = (tree_t *)malloc(sizeof(tree_t));
    assert(new_tree);
    new_tree->root = NULL;
    new_tree->cmp = cmp;
    new_tree->print = print;
    return new_tree;
}

int is_empty_tree(tree_t *tree){
    if (!tree || !tree->root){
        return 1;
    }
    return 0;
}

int search_tree(tree_t *tree, void *key){
    assert(tree);
    return recursive_search(tree->root, key, tree->cmp);
}

int recursive_search(node_t *root, void *key, int cmp(void*, void*)){
    int diff = cmp(((node_t *)key)->data, root->data);
    if (diff == 0){
        return 1;
    }
    else if (diff < 0){
        return recursive_search(root->left, key, cmp);
    }
    else{
        return recursive_search(root->right, key, cmp);
    }
}

tree_t *insert_tree(tree_t *tree, void *acc){
    assert(tree);
    node_t *new = node_init(acc);
    tree->root = recursive_insert(tree->root, new, tree->cmp);
    return tree;
}

node_t *recursive_insert(node_t *root, node_t *node, int cmp(void*, void*)){
    int diff;
    if (! root){
        return node;
    }
    else if ((diff= cmp(node->data, root->data)) < 0){
        root->left = recursive_insert(root->left, node, cmp);
    }
    else{
        root->right = recursive_insert(root->right, node, cmp);
    }
    return root;
}