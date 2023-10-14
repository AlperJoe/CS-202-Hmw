
/**
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 3
* Description : The program that creates an universe that has foods and
 greedy creatures who priorily wants stay alive and foods
 */

#ifndef Creature_h
#define Creature_h

#include "PriorityQueue.h"
#include <iostream>
#include <string>



using namespace std;

class Creature{
public:
    Creature();
    Creature(int cretureId, double xLocation, double yLocation, int health);
   
    int getId() ;
    int getHealth() ;
    double getX();
    double getY();
    void killed(Creature& creature);
    void setX(double xloc);
    void setY(double yloc);

    bool isInFightRange(Creature other);
    void fight(Creature& other);
    
    double getDistance( PriorityQueue food);
    //void moveToBestFood(PriorityQueue& foods);
    bool consumeFood(PriorityQueue& foods);
    void decreaseHealth();
    bool isAlive();
    


private:
    
    int creatureID;
    double xLocCreature;
    double yLocCreature;
    int health;
    int noOfCreature;
};


//void valhalla(Creature* creatures[], int& noOfCreatures);

#endif /* Creature_h */

