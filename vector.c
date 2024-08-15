#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct
{
    T *data;
    int size;
} VECTOR;

void create(VECTOR *vector, int size)
{
    vector->data = malloc(sizeof(T) * size);
    vector->size = (vector->data == NULL) ? 0 : size;
}

bool empty(VECTOR* vector)
{
    return vector->size == 0;
}

T load(VECTOR *vector, int ind)
{
    if (ind < vector->size && ind >= 0)
        return vector->data[ind];
}

bool save(VECTOR *vector, int ind, T el)
{
    if (ind < vector->size && ind >= 0)
    {
        vector->data[ind] = el;
        return true;
    }
    return false;
}

int get_size(VECTOR *vector)
{
    return vector->size;
}

bool equal(VECTOR *v1, VECTOR *v2)
{
    if (v1->size != v2->size)
        return false;
    for (int i = 0; i < v1->size; i++)
        if (v1->data[i] != v2->data[i])
            return false;
    return true;
}

VECTOR *resize(VECTOR *vector, int new_size)
{
    T *temp = realloc(vector->data, sizeof(T) * new_size);
    if (temp == NULL)
        return NULL;
    vector->data = temp;
    vector->size = new_size;
    return vector;
}

void destroy(VECTOR *vector)
{
    vector->size = 0;
    free(vector->data);
}

