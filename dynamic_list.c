#include <stdlib.h>
#include <stdbool.h>
#include "iterators.c"

typedef struct
{
    ITEM *head;
    int size;
} LIST;


bool create(LIST *l)
{
    l->head = malloc(sizeof(ITEM));
    if (l->head == NULL)
        return false;

    l->head->prev = l->head->next = l->head;
    l->size++;
    return true;
}

bool empty(LIST *l)
{
    return l->head->next == l->head->prev;
}

int size(LIST *l)
{
    return l->size;
}

ITERATOR first(const LIST *l)
{
    return (ITERATOR){l->head->next};
}

ITERATOR last(const LIST *l)
{
    return (ITERATOR){l->head->prev};
}

ITERATOR insert(LIST *l, ITERATOR *i, const T t)
{
    ITERATOR res = {malloc(sizeof(ITEM))};
    if (res.node == NULL)
        return last(l);

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
    if (equal(i, &res))
        return res;

    res.node = i->node->next;
    i->node->prev->next = res.node;
    res.node->prev = i->node->prev;
    free(i->node);
    i->node = 0;
    l->size--;
    return res;
}

void destroy(LIST *l)
{
    ITEM *i = l->head->next;

    while (i != l->head)
    {
        ITEM *pi = i;
        i = i->next;
        free(pi);
    }

    free(i);
    l->size = 0;
    l->head = NULL;
}