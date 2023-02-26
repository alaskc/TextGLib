// Dynamic array.

// note: Stolen code down there.

#include <stdlib.h>

#define __VECT_HEADER
#define __VECT_
#define __vect_init_c 2 * 2

typedef struct dvect {
    void **items;
    int capacity;
    int total;
} vector;

void vector_init(vector *v) {
    v->total = 0;
    v->capacity = __vect_init_c;
    v->items = malloc(sizeof(void *) * v->capacity);
}

void vector_resize(vector *v,int c) {
    void **items = realloc(v->items,sizeof(void*) * c);

    if (items) {
        v->items = items;
        v->capacity = c;
    }
}

void vector_add(vector *v, void *item)
{
    if (v->capacity == v->total)
        vector_resize(v, v->capacity * 2);
    v->items[v->total++] = item;
}

void vector_set(vector *v, int index, void *item)
{
    if (index >= 0 && index < v->total)
        v->items[index] = item;
}

void *vector_get(vector *v, int index)
{
    if (index >= 0 && index < v->total)
        return v->items[index];
    return NULL;
}

void vector_delete(vector *v, int index)
{
    if (index < 0 || index >= v->total)
        return;

    v->items[index] = NULL;

    for (int i = index; i < v->total - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4)
        vector_resize(v, v->capacity / 2);
}

void vector_free(vector *v)
{
    free(v->items);
}