#include <stdlib.h>
#include <stdio.h>

typedef struct _LinkedList{
    size_t item;
    struct _LinkedList *next;
} LinkedList;

void ll_insert(LinkedList *root, size_t value)
{
    if (root->next == NULL) {
        LinkedList* new_item = (LinkedList*)malloc(sizeof(LinkedList));
        new_item->item = value;
        root->next = new_item;
        return;
    }
    ll_insert(root->next, value);
}

LinkedList* ll_search(LinkedList *root, size_t value)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->item == value) {
        return root;
    }
    return ll_search(root->next, value);
}

void ll_print(LinkedList *root)
{
    if (root == NULL) {
        return;
    }
    printf("%zu\n", root->item);
    return ll_print(root->next);
}


int main()
{
    LinkedList ll_root = {0};
    for (size_t i=0;i<10000;++i) {
        ll_insert(&ll_root, i);
    }
    ll_print(&ll_root);
    return 0;
}
