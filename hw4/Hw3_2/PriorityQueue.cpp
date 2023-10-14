
/**
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 3
* Description : The program that creates an universe that has foods and
 greedy creatures who priorily wants stay alive and foods
 */


#include <stdio.h>
#include "PriorityQueue.h"
#include "Heap.h"
#include "Food.h"
#include <stdexcept>

using namespace std;


PriorityQueue::PriorityQueue(int size){
    h = new Heap(size);
}

/*
PriorityQueue::~PriorityQueue(){
    delete h;
}
*/

bool PriorityQueue::pqIsEmpty() const {
   return h -> heapIsEmpty();
}

void PriorityQueue::pqInsert(Food& newItem){
    h -> heapInsert(newItem);

}
void PriorityQueue::pqDelete(Food& priorityItem) {
    h -> heapDelete(priorityItem);
}
/*
void PriorityQueue::pqDeleteTop(){
    if(pqIsEmpty()){
        throw runtime_error("Its empty");
    }
    h -> heapDelete(h->getFirst());
}
 */
Food PriorityQueue::pqPeek(){
    if(pqIsEmpty()){
        //cout<<"Its empty"<<endl;
    }
    return h->getFirst();
}

void PriorityQueue::display(){
    h -> display();
}

