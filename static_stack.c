#include <stdbool.h>
#define POOL_SIZE 100

typedef int T;

typedef struct
{
    int size;
    T data[POOL_SIZE];
} STACK;

void create(STACK *s)
{
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

bool push(STACK *s, T t)
{
    if (s->size == POOL_SIZE)
        return false;

    s->data[s->size++] = t;
    return true;
}

bool pop(STACK *s)
{
    if (!s->size)
        return false;

    s->size--;
    return true;
}

T top(STACK *s)
{
    if (s->size)
        return s->data[s->size - 1];
}

void destroy(STACK *s)
{
    s->size = 0;
}
