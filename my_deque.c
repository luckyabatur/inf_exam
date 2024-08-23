#include <stdbool.h>
#include <stdlib.h>
#include <stdlib.h>

typedef int T;

typedef struct item
{
    struct item *prev;
    struct item *next;
    T data;
} ITEM;

typedef struct
{
    ITEM *left;
    ITEM *right;
    int size;
} DEQUE;

bool create(DEQUE *d)
{
    ITEM *l = malloc(sizeof(ITEM));
    if (!l)
        return false;
    ITEM *r = malloc(sizeof(ITEM));
    if (!r)
    {
        free(l);
        return false;
    }

    l->next = r;
    l->prev = r->next = NULL;
    r->prev = l;
    d->left = l;
    d->right = r;
    d->size = 0;
    return true;
}


bool empty(DEQUE *d)
{
    return d->left->next == d->right;
}

int size(DEQUE *d)
{
    return d->size;
}

bool l_push(DEQUE *d, T t)
{
    ITEM *i = malloc(sizeof(ITEM));
    if (!i)
        return false;

    i->data = t;
    i->next = d->left->next;
    i->prev = d->left;
    i->next->prev = i;
    d->left->next = i;
    d->size++;
    return true;
}

bool l_pop(DEQUE *d)
{
    if (empty(d))
        return false;

    ITEM *temp = d->left->next;
    d->left->next = d->left->next->next;
    d->left->next->prev = d->left;
    d->size--;
    free(temp);
    return true;
}

bool r_push(DEQUE *d, T t)
{
    ITEM *i = malloc(sizeof(ITEM));
    if (!i)
        return false;

    i->data = t;
    i->prev = d->right->prev;
    i->next = d->right;
    i->prev->next = i;
    d->right->prev = i;
    d->size++;
    return true;
}

bool r_pop(DEQUE *d)
{
    if (empty(d))
        return false;

    ITEM *temp = d->right->prev;
    d->right->prev = d->right->prev->prev;
    d->right->prev->next = d->right;
    d->size--;
    free(temp);
    return true;
}

T l_top(DEQUE *d)
{
    if (!empty(d))
        return d->left->next->data;
}

T r_top(DEQUE *d)
{
    if (!empty(d))
        return d->right->prev->data;
}

void destroy(DEQUE *d)
{
    while(!empty(d))
    {
        l_pop(d);
    }
    free(d->left);
    free(d->right);
    d->left = d->right = NULL;
    d->size = 0;
}



