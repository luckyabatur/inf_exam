#include <stdbool.h>

typedef int T;

typedef struct item
{
    struct item *next;
    struct item *prev;
    T data;
} ITEM;

typedef struct
{
    ITEM *node;
} ITERATOR;

ITERATOR *next(ITERATOR *i)
{
    i->node = i->node->next;
    return i;
}

ITERATOR *prev(ITERATOR *i)
{
    i->node = i->node->prev;
    return i;
}

T fetch(ITERATOR *i)
{
    return i->node->data;
}

void store(ITERATOR *i, T t)
{
    i->node->data = t;
}

bool equal(ITERATOR *a, ITERATOR *b)
{
    return a->node == b->node;
}

bool notequal(ITERATOR *a, ITERATOR *b)
{
    return a->node != b->node;
}