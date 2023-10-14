
/**
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 3
* Description : The program that creates an universe that has foods and
 greedy creatures who priorily wants stay alive and foods
 */

/**
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 3
* Description : The program that creates an universe that has foods and
 greedy creatures who priorily wants stay alive and foods
 */


#ifndef PriorityQueue_h
#define PriorityQueue_h

#include "Heap.h"

//typedef HeapItemType FoodtemType;
class PriorityQueue {
public:
    PriorityQueue(int size);
    //~PriorityQueue();
   // default constructor, copy constructor, and destructor
   // are supplied by the compiler
   // priority-queue operations:
    bool pqIsEmpty() const;
    void pqInsert(Food& newItem);
    void pqDelete(Food& priorityItem);
    Food pqPeek();
    void pqDeleteTop();
    void display();

private:
   Heap* h;
};

#endif /* PriorityQueue_h */
