#include "binary_search_tree.h"

static node_t *make_node(int value) {
    node_t *n = malloc(sizeof(node_t));
    // if (!n) return NULL;
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    printf("make node\n");
    printf("nt->data pos1: %d\n", n->data);
    printf("nt->right: %d, nt->right->data = %d\n", n->right == NULL, (n->right == NULL) ? 0 : n->right->data);
    printf("nt->left: %d, nt->left->data = %d\n", n->left == NULL, (n->left == NULL) ? 0 : n->left->data);
    return n;
}
static void inOrder(node_t *root, int *sorted_data)
{
    if (root != NULL)
    {   
        inOrder(root->left, sorted_data);
        printf("counter = %d\n", counter);
        printf(" root->data = %d\n", root->data);
        sorted_data[counter] = root->data;
        printf(" sorted_data[%d] = %d\n", counter, sorted_data[counter]);
        counter++;
        inOrder(root->right, sorted_data);
    }
}

static node_t *create_tree(node_t *root, int value) {
    if (root == NULL) {
        printf("root NULL\n");
        return make_node(value);
    }
    printf("nt->data pos2: %d\n", root->data);
    if (value <= root->data) {
        root->left = create_tree(root->left, value);
    } else if (value > root->data) {
        root->right = create_tree(root->right, value);
    }
    printf("nt->data pos3: %d\n", root->data);
    printf("nt->right: %d, nt->right->data = %d\n", root->right == NULL, (root->right == NULL) ? 0 : root->right->data);
    printf("nt->left: %d, nt->left->data = %d\n", root->left == NULL, (root->left == NULL) ? 0 : root->left->data);
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
