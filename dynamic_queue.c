#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct item
{
    T data;
    struct item *next;
} ITEM;

typedef struct
{
    ITEM *first;
    ITEM *last;
    int size;
} QUEUE;

bool create(QUEUE *q)
{
    q->size = 0;
    q->first = q->last = malloc(sizeof(ITEM));
    if (q->first == NULL)
    {
        return false;
    }
    q->first->next = NULL;
    return true;
}

bool empty(QUEUE *q)
{
    return q->size == 0; //return q->first == q->last;
}

int size(QUEUE *q)
{
    return q->size;
}


bool push(QUEUE *q, T t)
{
    if ((q->last->next = malloc(sizeof(ITEM))) == NULL)
        return false;

    q->last->data = t;
    q->last = q->last->next;
    q->last->next = NULL;
    q->size++;
    return true;
}

bool pop(QUEUE *q)
{
    if (!q->size)
        return false;

    ITEM *temp = q->first;
    q->first = q->first->next;
    free(temp);
    q->size--;
    return true;
}

T top(const QUEUE *q)
{
    if (q->size)
        return q->first->data;
}

void destroy1(QUEUE *q)
{
    while (q->size)
    {
        ITEM *temp = q->first;
        q->first = q->first->next;
        free(temp);
        q->size--;
    }

    free(q->first);
    q->first = q->last = NULL;
}

void destroy2(QUEUE *q)
{
    q->last->next = 0;
    ITEM *temp = q->first;
    q->first = q->first->next;
    free(temp);

    if (q->first)
        destroy2(q);

    q->size = 0;

    q->last = NULL;
}

void reverse(QUEUE *q)
{
    if (!empty(q))
    {
        T temp = top(q);
        pop(q);
        reverse(q);
        push(q, temp);
    }
}
