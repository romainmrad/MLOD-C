// =========
// Romain MRAD
// =========

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// constructs a new (empty) list
List *list_create(void)
{
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const List *list)
{
    size_t count = 0;

    ListNode *p = list->first;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}

// inserts item_data at *end* of a list
void list_addlast(List *list, data_t item_data)
{
    ListNode *ptr = malloc(sizeof(ListNode));
    ptr->data = item_data;
    if (list_count(list) == 0)
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        list->first = ptr;
        list->last = ptr;
    }
    else
    {
        ptr->prev = list->last;
        ptr->next = NULL;
        list->last->next = ptr;
        list->last = ptr;
    }
}

// removes the item from *end* of the list and returns its value
data_t list_rmlast(List *list)
{
    if (list_count(list) == 1)
    {
        data_t res = list->first->data;
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        return res;
    }
    else if (list_count(list) > 1)
    {
        data_t res = list->last->data;
        list->last = list->last->prev;
        free(list->last->next);
        list->last->next = NULL;
        return res;
    }
    return -1;
}

void list_print(List *list)
{
    printf("List values: ");
    ListNode *ptr = list->first;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// void list_destruct(List *list)
// {
//     while (list_count(list) > 1)
//     {
//         list->last = list->last->prev;
//         free(list->last->next);
//     }
//     free(list->first);
//     // free(list);
// }

void list_destruct(List *list)
{
    if (list_count(list) > 0)
    {
        ListNode *current = list->first;
        while (current != NULL)
        {
            ListNode *temp = current;
            current = current->next;
            free(temp);
        }
        list->first = NULL;
        list->last = NULL;
        free(list);
    }
}

/*
Il manquait la fonction list_print permettant l'affichage des elements d'une liste.
Il faut donc déclarer sa signature dans list.h et l'implémenter dans list.c.

Par ailleurs, il manque aussi une fonction permettant la destruction d'une liste
afin de libérer l'espace mémoire qui lui a été alloué.
*/

int main(void)
{

    printf("Testing list_create, list_addlast and list_print\n");
    List *l = list_create();

    assert(list_count(l) == 0);

    list_addlast(l, 10);
    list_addlast(l, 20);
    list_addlast(l, 30);
    list_addlast(l, 40);

    assert(list_count(l) == 4);

    list_print(l);

    printf("\n\nTesting list_rmlast\n");
    data_t t = list_rmlast(l);
    printf("Removed last item: %i\n", t);
    assert(t == 40);
    list_print(l);

    printf("\n\nDestroying list");
    list_destruct(l);
    return 0;
}