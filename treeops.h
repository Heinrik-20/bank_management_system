#ifndef TREEOPS_H
#define TREEOPS_H

typedef struct node node_t;

struct node {
    void *data;
    node_t *left;
    node_t *right;
};

typedef struct {
    node_t *root;
    int total_elements;
    int (*cmp) (void*, void*);
    void (*print) (void*);
} tree_t;

void traverse_tree(node_t *tree, void action(void*));
node_t *node_init(void *data);
tree_t *tree_init(int cmp(void*, void*), void print(void*));
int is_empty_tree(tree_t *tree);
node_t *search_tree(tree_t *tree, void *key);
node_t *recursive_search(node_t *root, void *key, int cmp(void*, void*));
tree_t *insert_tree(tree_t *tree, void *acc);
node_t *recursive_insert(node_t *root, node_t *node, int cmp(void*, void*));
void free_tree(tree_t **tree);

#endif
