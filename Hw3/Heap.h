
/**
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 3
* Description : The program that creates an universe that has foods and
 greedy creatures who priorily wants stay alive and foods
 */

#ifndef Heap_h
#define Heap_h

#include "Food.h"


const int MAX_FOOD = 30;

typedef Food HeapItemType;

class Heap{
public:
    Heap(int newSize);
    //~Heap();
    
    bool heapIsEmpty() const;
    void heapInsert(Food& newItem);
    void heapDelete(Food& rootItem);
    Food getFirst();
    void display();

protected:
    void heapRebuild(int root);
private:
    Food* items;
    int maxsize;
    int size;
};

#endif /* Heap_h */
