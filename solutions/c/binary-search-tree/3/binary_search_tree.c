#include "binary_search_tree.h"
static int counter;
static node_t *make_node(int value) {
    node_t *n = malloc(sizeof(node_t));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
static void inOrder(node_t *root, int *sorted_data)
{
    if (root != NULL)
    {   
        inOrder(root->left, sorted_data);
        sorted_data[counter] = root->data;
        counter++;
        inOrder(root->right, sorted_data);
    }
}

static node_t *create_tree(node_t *root, int value) {
    if (root == NULL) {
        return make_node(value);
    }
    if (value <= root->data) {
        root->left = create_tree(root->left, value);
    } else if (value > root->data) {
        root->right = create_tree(root->right, value);
    }
    return root;
}

node_t *build_tree(int *tree_data, size_t tree_data_len) {
    node_t *nt = malloc(sizeof(int) + sizeof(*nt));
    nt->data = *tree_data;
    nt->left = nt->right = NULL;
    for (size_t i = 1; i < tree_data_len; i++)
    {
        nt = create_tree(nt, tree_data[i]);
    }
    return nt;
}

void free_tree(node_t *tree) {
    free(tree);
}
int *sorted_data(node_t *tree) {
    if (tree == NULL) return 0;
    int *sorted_data = malloc(sizeof(node_t));
    counter = 0;
    inOrder(tree, sorted_data);
    return sorted_data;
}
int min(node_t *tree) {
    if (tree->left == NULL) return tree->data;
    return min(tree->left);
}
int max(node_t *tree) {
    if (tree->left == NULL) return tree->data;
    return min(tree->right);
}
