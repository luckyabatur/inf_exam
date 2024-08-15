#include <stdbool.h>

#define POOL_SIZE 100

typedef int T;

typedef struct
{
    int first;
    int size;

    T data[POOL_SIZE];
} QUEUE;

void create(QUEUE *q)
{
    q->first = 0;
    q->size = 0;
}

bool empty(QUEUE *q)
{
    return q->size == 0;
}

int size(QUEUE *q)
{
    return q->size;
}

bool push(QUEUE *q, T el)
{
    if (q->size == POOL_SIZE)
        return false;

    q->data[(q->first + q->size++) % POOL_SIZE] = el;
    return true;
}

bool pop(QUEUE *q)
{
    if (!q->size)
        return false;

    q->first++;
    q->first %= POOL_SIZE;
    q->size--;

    return true;
}

T top(QUEUE *q)
{
    if (q->size)
        return q->data[q->first];
}

void destroy(QUEUE *q)
{
    q->size = 0;
}