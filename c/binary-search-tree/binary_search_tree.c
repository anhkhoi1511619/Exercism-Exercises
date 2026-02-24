#include "binary_search_tree.h"

node_t *build_tree(int *tree_data, size_t tree_data_len) {
    node_t *nt = malloc(sizeof(int) + tree_data_len * sizeof(int));
    printf("size %zu\n", tree_data_len);
    nt->data = *tree_data++;
    printf("nt->data %d\n", nt->data);
    node_t *tmp_nt = malloc(sizeof(int));
    for (size_t i = 1; i < tree_data_len; i++) {
        printf("data = %d i = %zu\n", *tree_data, i);
        tmp_nt->data = *tree_data++;
        if (tmp_nt->data > nt->data) {
            printf("right tmp_nt->data: %d > nt->data: %d\n", tmp_nt->data, nt->data);
            nt->right = tmp_nt;
        } else {
            printf("left tmp_nt->data: %d <= nt->data: %d\n", tmp_nt->data, nt->data);
            nt->left = tmp_nt;
        }
        printf("nt->right: %d\n", nt->right == NULL);
        printf("nt->left: %d\n", nt->left == NULL);
        tmp_nt = realloc(tmp_nt, sizeof(int));
    }
    // for(size_t i = 0; i < tree_data_len; i++) {
    //     printf("data %d\n", tree_data[i]);
    //     if ()
    // }
    return nt;
}
void free_tree(node_t *tree) {
    free(tree);
}
int *sorted_data(node_t *tree) {
    if (tree == NULL) return 0;
    return &(tree->data);
}
