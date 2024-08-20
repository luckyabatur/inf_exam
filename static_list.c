#include "iterators.c"
#include <stdlib.h>

#define POOL_SIZE 100


typedef struct
{
    ITEM *top;
    ITEM *head;
    ITEM data[POOL_SIZE + 1];
    int size;
} LIST;


ITERATOR first(LIST *l)
{
    return (ITERATOR){l->head->next};
}

ITERATOR last(LIST *l)
{
    return (ITERATOR){l->head->prev};
}

void create(LIST *l)
{
    for (int i = 0; i < POOL_SIZE-1; i++)
        l->data[i].next = &l->data[i+1];

    l->data[POOL_SIZE - 1].next = NULL;
    l->top = &l->data[0];
    l->head = &l->data[POOL_SIZE];
    l->head->prev = l->head->next = l->head;
    l->size = 0;
}

ITERATOR insert(LIST *l, ITERATOR *i, T t)
{
    ITERATOR res = last(l);
    if (l->top == NULL)
        return res;

    res.node = l->top;
    l->top = l->top->next;
    res.node->data = t;
    res.node->next = i->node;
    res.node->prev = i->node->prev;
    res.node->prev->next = res.node;
    i->node->prev = res.node;
    l->size++;

    return res;
}

ITERATOR delete(LIST *l, ITERATOR *i)
{
    ITERATOR res = last(l);
    if (equal(&res, i))
        return res;

    res.node = i->node->next;
    i->node->prev->next = res.node;
    res.node->prev = i->node->prev;
    i->node->next = l->top;
    l->top = i->node;
    i->node = NULL;
    l->size--;

    return res;
}

void destroy(LIST *l)
{
    l->size = 0;
    l->top = 0;
    l->head = 0;
}

