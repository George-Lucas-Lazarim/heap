#include "heap.h"

struct maxHeap* initHeap (int capacity) {
    if (capacity <= 0) {
        printf("\nError! Invalid capacity");
        return NULL;
    }

    struct maxHeap* heap = (struct maxHeap*) malloc (sizeof(struct maxHeap));

    if (heap == NULL) {
        printf("\nError! Memory allocation failed for heap");
        return NULL;
    }

    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (int*) malloc (capacity * sizeof(int));

    return heap;
}

int parent (int i) { return ((i - 1) / 2); }

int leftChild (int i) { return ((i * 2) + 1); }

int rightChild (int i) { return ((i * 2) + 2); }

void swap (int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}

void insert (struct maxHeap* heap, int data) {
    if (heap->size == heap->capacity) {
        printf("\nError! It is not possible to add more data (maximum capacity reached)");
        return;
    }

    int i = heap->size;
    heap->array[i] = data;
    heap->size++;

    while (i != 0 && heap->array[parent(i)] < heap->array[i]) {
        swap(&heap->array[parent(i)], &heap->array[i]);

        i = parent(i);
    }
}

void printHeap (struct maxHeap* heap) {
    printf("\n");
    for (int i = 0; i < heap->size; i++) printf("%d ", heap->array[i]);
}