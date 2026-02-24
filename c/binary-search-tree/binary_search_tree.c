#include "binary_search_tree.h"
// static void traverse(node_t *node);

node_t *build_tree(int *tree_data, size_t tree_data_len) {
    node_t *nt = malloc(sizeof(int) + tree_data_len * sizeof(int));
    printf("size %zu\n", tree_data_len);
    nt->data = *tree_data++;
    printf("nt->data %d\n", nt->data);
    for (size_t i = 1; i < tree_data_len; i++) {
        // printf("data = %d i = %zu\n", *tree_data, i);
        int data = *tree_data++;
        if (data > nt->data) {
            printf("right tmp_nt->data: %d > nt->data: %d\n", data, nt->data);
            nt->right = malloc(sizeof(int));
            nt->right->data = data;
        } else {
            printf("left tmp_nt->data: %d <= nt->data: %d\n", data, nt->data);
            nt->left = malloc(sizeof(int));
            nt->left->data = data;
        }
        printf("nt->right: %d, nt->right->data = %d\n", nt->right == NULL, (nt->right == NULL) ? 0 : nt->right->data);
        printf("nt->left: %d, nt->left->data = %d\n", nt->left == NULL, (nt->left == NULL) ? 0 : nt->left->data);
        // tmp_nt = realloc(tmp_nt, sizeof(int));
    }
    // traverse(nt);
    // for(size_t i = 0; i < tree_data_len; i++) {
    //     printf("data %d\n", tree_data[i]);
    //     if ()
    // }
    return nt;
}
// static void traverse(node_t *node)
// {
//     if (node == NULL) return;
//     printf("%d\n", node->data);

//     traverse(node->left);
//     traverse(node->right);
// }
void free_tree(node_t *tree) {
    free(tree);
}
int *sorted_data(node_t *tree) {
    if (tree == NULL) return 0;
    return &(tree->data);
}
