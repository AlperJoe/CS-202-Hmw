
/**
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 3
* Description : The program that creates an universe that has foods and
 greedy creatures who priorily wants stay alive and foods
 */

#include <stdio.h>
#include "Creature.h"
#include <cmath>
#include "PriorityQueue.h"
#include "Food.h"
#include <iostream>

using namespace std;

Food::Food(){
    
}

Food::Food(int foodId, int xLocation, int yLocation, int quality, int sTime){
    foodID = foodId;
    xLocFood = xLocation;
    yLocFood = yLocation;
    qualityFood = quality;
    spawnTime = sTime;
}

int Food::getId(){
    return foodID;
}
double Food::getX(){
    return xLocFood;
}
double Food::getY(){
    return yLocFood;
}
int Food::getQuality(){
    return qualityFood;
}
int Food::getSpawnTime(){
    return spawnTime;
}

/*
 void Food::addFood(PriorityQueue& extraFoods, PriorityQueue& availableFoods){
     Food potentialFood = extraFoods.pqPeek();
     if(potentialFood.getSpawnTime() == 0){
         availableFoods.pqInsert(potentialFood);
     }
 }
 */
