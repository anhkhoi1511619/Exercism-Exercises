#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[])
{
    list_t *new_list = malloc(sizeof(size_t) + sizeof(list_element_t) *length);
    new_list->length = length;
    printf("create new list with length: %zu\n", length);
    if (length != 0) {
        memcpy(new_list->elements, 
                    elements, 
                        length * sizeof(list_element_t));
    }
    return new_list;
}
list_t *append_list(list_t *list1, list_t *list2)
{
    list_t *lt = malloc(sizeof(size_t) + 
                            sizeof(list_element_t) * (list1->length + list2->length));
    printf("list1 length %zu, list2 length %zu\n", list1->length, list2->length);
    lt->length = list1->length + list2->length;
    if (list1->length != 0) {
        memcpy (lt->elements, 
                    list1->elements, 
                        sizeof(list_element_t) * list1->length);
    }
    if (list2->length != 0) {
        memcpy (lt->elements  + list1->length, 
                    list2->elements, 
                        sizeof(list_element_t) * list2->length);
    }
    printf("Size of append_list %zu\n", lt->length);
    for(size_t i = 0; i < lt->length; i++)
    {
        printf("element %d\n", lt->elements[i]);
    }
    return lt;
}
list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
    list_t *tmp_lt = malloc(sizeof(size_t) + 
                            sizeof(list_element_t) * list->length);
    list_t *lt = malloc(sizeof(size_t) + 
                            sizeof(list_element_t) * list->length);                        
    list_element_t count = 0;
    for (size_t i = 0; i < list->length; i++) {
        if (filter(list->elements[i])) {
            tmp_lt->elements[count] = list->elements[i];
            printf("filter is OK count = %d, add element = %d\n", count, tmp_lt->elements[count]);
            count++;
            continue;
        }
        printf("filter is NOT OK %zu\n", tmp_lt->length);
    }
    tmp_lt->length = count;
    lt = realloc (lt, sizeof (size_t) + count * sizeof(list_element_t));  
    lt->length = count;
    memcpy(lt->elements, tmp_lt->elements, count * sizeof(list_element_t));
    free(tmp_lt); 
    return lt;                     
}
size_t length_list(list_t *list)
{
    return list->length;
}
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
    list_t *lt = malloc(sizeof(size_t) + list->length * sizeof(list_element_t));
    lt->length = list->length;
    for (size_t i = 0; i < list->length; i++) {
        lt->elements[i] = map(list->elements[i]);
    }
    return lt;
}
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t))
{
    if(list->length == 0) return initial;
    list_element_t result = initial;
    for (size_t i = 0; i < list->length; i++) {
        result = foldl(result, list->elements[i]);
    }
    return result;
}
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t))
{
    if(list->length == 0) return initial;
    list_element_t result = initial;
    for (ssize_t i = list->length - 1; i >= 0; i--) {
        result = foldr(list->elements[i], result);
    }
    return result;
}
void delete_list(list_t *list)
{
    free(list);
}
list_t *reverse_list(list_t *list)
{
    list_t *lt = new_list(list->length, list->elements);
    for (ssize_t i = list->length - 1; i >= 0; i--) {
        printf("Running i = %zu, element = %d\n", i, list->elements[list->length - i - 1]);
        lt->elements[i] = list->elements[list->length - i - 1];
    }
    return lt;
}
