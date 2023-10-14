
/**
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 3
* Description : The program that creates an universe that has foods and
 greedy creatures who priorily wants stay alive and foods
 */
#include <stdio.h>

#include "Heap.h"
#include "Food.h"


Heap::Heap(int newsize)
{
    items = new HeapItemType[newsize];
    maxsize = newsize;
    size = 0;
}

/*
Heap::~Heap()
{
    delete[] items;
}
*/
Food Heap::getFirst(){
    return items[0];
}

bool Heap::heapIsEmpty() const{
    return (size == 0);
}

void Heap::heapInsert(Food& newItem){

    if (size < maxsize){
        // Place the new item at the end of the heap
        items[size] = newItem;

        // Trickle new item up to its proper position
        int place = size;
        int parent = (place - 1)/2;
        while ( (place > 0) && (items[place].getQuality() > items[parent].getQuality()) ) {
            HeapItemType temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
        ++size;
    }
}

void Heap::heapDelete(Food&rootItem)
{
    if (!heapIsEmpty()){
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }
}

void Heap::heapRebuild(int root)
{
    int child = 2 * root + 1;     // index of root's left child, if any
    if ( child < size )
    {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;     // index of a right child, if any
        // If root has right child, find larger child
        if ( (rightChild < size) && (items[rightChild].getQuality() >items[child].getQuality()) )
        {
            child = rightChild;     // index of larger child
        }
        // If root’s item is smaller than larger child, swap values
        if ( items[root].getQuality() < items[child].getQuality())
        {
            HeapItemType temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}
void Heap::display(){
    if(heapIsEmpty()){
        cout<<"Heap is empty"<<endl;
    }else{
        for(int i = 0; i < size; i++){
            cout<<"ID: "<< items[i].getId()<<" x: "<<items[i].getX()<<" y: "<<items[i].getY()<<" qu: "<<items[i].getQuality()<<" stime: "<<items[i].getSpawnTime()<<endl;
        }
    }
}
