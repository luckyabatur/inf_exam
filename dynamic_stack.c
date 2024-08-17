#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct item
{
    T data;
    struct item *prev;
} ITEM;

typedef struct
{
    ITEM *top;
    int size;
} STACK;

void create(STACK *s)
{
    s->top = NULL;
    s->size = 0;
}

bool empty(STACK *s)
{
    return s->size == 0;
}

int size(STACK *s)
{
    return s->size;
}

T top(STACK *s)
{
    if (!empty(s))
        return s->top->data;
}

bool push(STACK *s, T t)
{
    ITEM *i = malloc(sizeof(ITEM));
    if (i == NULL)
        return false;

    i->prev = s->top;
    i->data = t;
    s->top = i;
    s->size++;
    return true;
}

bool pop(STACK *s)
{
    if (empty(s))
        return false;

    ITEM *i = s->top;
    s->top = s->top->prev;
    s->size--;
    free(i);
    return true;
}

void destroy(STACK *s)
{
    while (s->top)
    {
        ITEM *i = s->top;
        s->top = s->top->prev;
        free(i);
    }

    s->size = 0;
}


