#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

struct maxHeap {
    int *array;
    int capacity;
    int size;
};

struct maxHeap* initHeap (int capacity);
int parent (int i);
int leftChild (int i);
int rightChild (int i);
void swap (int *x, int *y);
void insert (struct maxHeap* heap, int data);
void printHeap (struct maxHeap* heap);

#endif