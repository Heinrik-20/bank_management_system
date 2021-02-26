#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "account.h"
#include "treeops.h"

void traverse_tree(node_t *node, void action(void *)){
    if (node) {
        traverse_tree(node->left, action);
        traverse_tree(node->right, action);
        action(node);
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

node_t *search_tree(tree_t *tree, void *key){
    assert(tree);
    return recursive_search(tree->root, key, tree->cmp);
}

node_t *recursive_search(node_t *root, void *key, int cmp(void*, void*)){
    if (!root){
        return NULL;
    }
    int diff = cmp(((node_t *)key)->data, root->data);
    if (diff == 0){
        return root;
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
    if (search_tree(tree, new)){
        printf("Account already in database\n");
        return tree;
    }
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

void free_tree(tree_t **tree){
    free(*tree);
    *tree = NULL;
    return;
}
