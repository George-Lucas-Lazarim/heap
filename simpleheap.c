#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

#define SIZE 5

int main() {
    struct maxHeap* heap = initHeap(SIZE);

    int aux;

    for (int i = 0; i < SIZE; i++) {
        printf("\nEnter an integer to add to the heap: ");
        scanf("%d", &aux);
        insert(heap, aux);
        printf("Number: %d added successfully!", aux);
        printHeap(heap);
        printf("\n\n");
    }

    free(heap->array);
    free(heap);
}