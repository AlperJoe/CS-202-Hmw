
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

Creature::Creature(){
    
}

Creature::Creature(int creatureId,  double xLocation, double yLocation, int creatureHealth){
    creatureID = creatureId;
    health = creatureHealth;
    xLocCreature= xLocation;
    yLocCreature = yLocation;
}


int Creature::getId()  { return creatureID; }
int Creature::getHealth()   { return health; }
double Creature::getX()  { return xLocCreature; }
double Creature::getY()  { return yLocCreature; }

void Creature::setX(double xloc){
    xLocCreature = xloc;
}
void Creature::setY(double yloc){
    yLocCreature = yloc;
}


void Creature::killed(Creature& creature){creature.health = 0;}


bool Creature::isInFightRange(Creature other){
    double distance = sqrt(pow(xLocCreature - other.getX(),2) + pow(yLocCreature - other.getY(),2) );
    //cout<<"-----"<<distance<<"-----"<<endl;
    return (distance <= 2);
}

void Creature::fight(Creature& other){
    if (health >= other.getHealth() && other.getHealth() > 0) {
        //cout << "Creature " << creatureID<< " killed creature " << other.getId()<<endl;
        killed(other);
    }
}

void Creature::decreaseHealth() {
    if (health > 0) {
        health --;
    }
}

bool Creature::isAlive(){
    return health > 0;
}


double Creature:: getDistance(PriorityQueue foods){
    Food bestFood = foods.pqPeek();
    double targetX = bestFood.getX();
    double targetY = bestFood.getY();
    //double distanceX = targetX - xLocCreature;
    //double distanceY = targetY - yLocCreature;
    
    double distance = sqrt(pow(xLocCreature - targetX,2) + pow(yLocCreature - targetY,2) );
    //cout<<distance<<endl;
    return distance;
    //sqrt(distanceX * distanceX + distanceY * distanceY);
}

bool Creature::consumeFood(PriorityQueue& foods){
    double consumableDistance = 1;
    double distance = this->getDistance(foods);
    Food bestFood = foods.pqPeek();
    if(distance < consumableDistance && (isAlive())){
        health += bestFood.getQuality();
        //cout<<getId()<<endl;
        //cout<<"Food is eaten"<<endl;
        foods.pqDelete(bestFood);
        return true;
    }
    return false;
}



/*
 void Creature::moveToBestFood(PriorityQueue& foods){
     if(foods.pqIsEmpty()){
         cout<<"No Food Right now"<<endl;
         return;
     }
      
     if(health <= 0){
         return;
     }
     
     double velocity = 0;
     if (health > 10) {
         velocity = 10/health;
     }
     else if (health > 0) {
         velocity = 1;
     }
         
    // cout<<"Distance is "<<distanceToBestFood<<endl;
     
     Food f = foods.pqPeek();
     
     double distanceX = f.getX() - xLocCreature;
     double distanceY = f.getY() - yLocCreature;
     double distance = sqrt((distanceX*distanceX)+(distanceY*distanceY));
     

     cout<<foods.pqPeek().getX()<<endl;
     cout<<distanceX<<endl;
     cout<<distance<<endl;
     cout<<velocity<<endl;

     //cout<<xLocCreature<<endl;
     xLocCreature += (distanceX/distance) * velocity;
     //cout<<xLocCreature<<endl;
     yLocCreature += (distanceY/distance) * velocity;
 }

 void Creature::moveToBestFood(PriorityQueue* foods) {
     // Find the best food
 
 Food* bestFood = foods->peek();

     // If no food is available, don't move
     if (bestFood == nullptr) {
         return;
     }

     // Calculate distance to the best food
     double dx = bestFood->getX() - x;
     double dy = bestFood->getY() - y;
     double distance = std::sqrt(dx*dx + dy*dy);

     // If the creature is within eating distance of the best food, eat it
     if (distance <= 1.0) {
         eat(bestFood);
         foods->pop();
         return;
     }

     // Otherwise, move towards the best food
     double moveDist = std::min(health, 10.0) / 10.0;
     x += dx * moveDist / distance;
     y += dy * moveDist / distance;
 }

 */
/*
void Creature::fight(Creature* other) {
    if (isInFightRange(*other)) {
        cout << "Creature " << creatureID << " killed creature " << other->getId() <<endl;
        other->health = 0;
    }
}
 
 void Creature::valhalla(Creature* creatures[], int& noOfCreatures){
     for(int i = 0; i < noOfCreatures; i++){
         Creature* other = creatures[i];
         if(other != this){
             double distance = sqrt(pow(other -> xLocCreature - xLocCreature, 2) + pow(other -> yLocCreature - yLocCreature, 2));
             if(distance < 2 && other -> getHealth() <= health){
                 cout << "Creature " << creatureID << " killed creature " << other->getId() << endl;
                 creatures[i] = creatures[noOfCreatures - 1];
                 noOfCreatures --;
                 i--;
                 delete other;
             }
         }
     }
 }
*/
