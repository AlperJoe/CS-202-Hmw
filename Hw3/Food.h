
/**
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 3
* Description : The program that creates an universe that has foods and
 greedy creatures who priorily wants stay alive and foods
 */


#ifndef Food_h
#define Food_h

#include <cmath>
#include <iostream>

using namespace std;

class Food{
public:
    Food();
    Food(int foodId, int xLocation, int yLocation, int quality, int sTime);
    
    
    bool operator<(const Food& f)const{
        return qualityFood < f.qualityFood;
    }
    int getId();
    double getX();
    double getY();
    int getQuality();
    int getSpawnTime();
    //void addFood(PriorityQueue& extraFoods, PriorityQueue& availableFoods);
    
private:
    int foodID;
    int xLocFood;
    int yLocFood;
    int qualityFood;
    int spawnTime;
    int noOfFood;
};


#endif /* Food_h */
