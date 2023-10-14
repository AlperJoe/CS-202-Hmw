
/**
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 3
* Description : The program that creates an universe that has foods and
 greedy creatures who priorily wants stay alive and foods
 */


#include "Creature.h"
#include "Food.h"
#include <fstream>
#include <string>
#include <iomanip>
#include "PriorityQueue.h"



using namespace std;

void orderID(Creature arr[], int noOfCreatures){
    Creature key;
    int i,j;
    for(i = 1; i < noOfCreatures; i++){
        key = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j].getId() > key.getId()){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
        //cout<<temp.getId() << ".\t" << temp.getX()<< "\t"<< temp.getY() << endl;
    }
}

void printCreatures(Creature arr[], int noOfCreatures){
    for(int i = 0; i < noOfCreatures; i++){
        cout<<"Creature "<<arr[i].getId() << ": " << fixed<< setprecision(2)<< arr[i].getX()<< " "<<fixed<< setprecision(2)<< arr[i].getY() << endl;
    }
    //"\t"<<arr[i].getHealth()<< 
    //cout<<"--------------------------------------------"<<endl;
}

bool allCreaturesDead(Creature creatures[],int noOfCreatures)  {
    for (int i = 0; i < noOfCreatures; i++) {
        if (creatures[i].isAlive()) {
            return false;
        }
    }
    return true;
}

void resolveFights(Creature creatures[], int noOfCreatures){
    for(int i = 0; i < noOfCreatures; i++){
        if(creatures[i].isAlive()){
            for(int j = 0; j < noOfCreatures; j++){
                //cout<<"id: " <<creatures[j].getId()<<"     "<<creatures[i].isInFightRange(creatures[j])<<"  "<<creatures[j].isAlive()<<endl;
               // cout<<"i: "<<i<<" j: "<<j<<endl;
                if(i==2 && j == 3){
                    //cout<<"----------------"<<creatures[j].isInFightRange(creatures[i])<<endl;
                }
                
                if(i!=j && creatures[j].isAlive() && creatures[i].isInFightRange(creatures[j])){
                    creatures[i].fight(creatures[j]);
                }
            }
        }
    }
}

void addFood(PriorityQueue& extraFoods, PriorityQueue& availableFoods, int time){
    Food potentialFood = extraFoods.pqPeek();
    if(potentialFood.getSpawnTime() <= time && (!extraFoods.pqIsEmpty())){
        availableFoods.pqInsert(potentialFood);
        //cout<<potentialFood.getSpawnTime()<<endl;
        extraFoods.pqDelete(potentialFood);
    }
}

//array to queue according to food's spawn time
void arrayToQueueSpawnTime(PriorityQueue& exfoods, Food foodsNotOrdered[], int noOfFoods){
    Food key;
    int i,j;
    for(i = 1; i < noOfFoods; i++){
        key = foodsNotOrdered[i];
        j = i - 1;
        
        while(j >= 0 && foodsNotOrdered[j].getSpawnTime() > key.getSpawnTime()){
            foodsNotOrdered[j+1] = foodsNotOrdered[j];
            j = j - 1;
        }
        foodsNotOrdered[j+1] = key;
    }
    for(int i = noOfFoods-1; i >= 0; i--){
        exfoods.pqInsert(foodsNotOrdered[i]);
    }
}

void arrayToQueueFoodQualify(PriorityQueue& availFoods, Food foodsNotOrdered[], int noOfFoods){
    Food key;
    int i,j;
    for(i = 1; i < noOfFoods; i++){
        key = foodsNotOrdered[i];
        j = i - 1;
        while(j >= 0 && foodsNotOrdered[j].getQuality() > key.getQuality()){
            foodsNotOrdered[j+1] = foodsNotOrdered[j];
            j = j - 1;
        }
        foodsNotOrdered[j+1] = key;
    }
    for(int i = noOfFoods - 1; i >= 0; i--){
        availFoods.pqInsert(foodsNotOrdered[i]);
    }
}
void moveToBestFood(PriorityQueue& foods, Creature& creature){
    if(foods.pqIsEmpty()){
        //cout<<"No Food Right now"<<endl;
        return;
    }
     
    if(creature.getHealth() <= 0){
        return;
    }
    
    double velocity = 0;
    //cout<<creature.getHealth()<<endl;
    if (creature.getHealth() > 10) {
        velocity = 10.0/creature.getHealth();
    }
    else if (creature.getHealth() > 0) {
        velocity = 1;
    }
        
   // cout<<"Distance is "<<distanceToBestFood<<endl;
    
    Food f = foods.pqPeek();
    
    double distanceX = f.getX() - creature.getX();
    double distanceY = f.getY() - creature.getY();
    double distance = sqrt((distanceX*distanceX)+(distanceY*distanceY));
    
/*
    cout<<foods.pqPeek().getX()<<endl;
    cout<<"dx: "<<distanceX<<endl;
    cout<<"dy: "<<distanceY<<endl;
    cout<<"d: "<<distance<<endl;
    cout<<"vel: "<<velocity<<endl;
*/
    
    //cout<<xLocCreature<<endl;
    creature.setX(creature.getX() + (distanceX/distance) * velocity);
    //cout<<xLocCreature<<endl;
    creature.setY(creature.getY() + (distanceY/distance) * velocity);
}

int main(int argc, char** argv) {
    
    
     //dijkstra compile
     string filename(argv[1]);
     fstream myfile(filename);
     string line;
     getline(myfile, line);
    
    
    /*
    fstream myfile("/Users/alperbozkurt/Desktop/CS-202-02/hw3/hw3/hw3/data.txt");
    string line;
    getline(myfile,line);

    */
    
    const int noOfCreatures = stoi(line);
    
    PriorityQueue extraFoods = *new PriorityQueue(MAX_FOOD);
    PriorityQueue availableFoods = *new PriorityQueue(MAX_FOOD);
    
    if(noOfCreatures > 30){
        cout<<"too many creatures"<<endl;
        return 0;
    }
    
    Creature creatures[30];
    
    //for loop the add creatures to the array from data.txt
    for(int i = 0; i < noOfCreatures; i++){
        
        getline(myfile, line);
        int tempId;
        double x;
        double y;
        int health;
        
        size_t startPos = 0;
        size_t commaPos = line.find(",");
        string numStr = line.substr(startPos, commaPos - startPos);
        tempId = stoi(numStr);

        startPos = commaPos + 1;
        commaPos = line.find(",", startPos);
        numStr = line.substr(startPos, commaPos - startPos);
        x = stod(numStr);

        startPos = commaPos + 1;
        commaPos = line.find(",", startPos);
        numStr = line.substr(startPos, commaPos - startPos);
        y = stod(numStr);

        startPos = commaPos + 1;
        numStr = line.substr(startPos);
        health = stoi(numStr);

        Creature newCreature = Creature(tempId, x, y, health);
        creatures[i] = newCreature;
        
    }
    int noOfAvailableFoods = 0;
    int noOfExtraFoods = 0;
    int availIndex = 0;
    int extraIndex = 0;
    
    Food availFoodArr[MAX_FOOD];
    Food extraFoodArr[MAX_FOOD];
    
    while (getline(myfile, line)) {
        
        int tempID;
        double x;
        double y;
        int tempQuality;
        int spawnTime;
        
        
        size_t startPos = 0;
        size_t commaPos = line.find(",");
        string numStr = line.substr(startPos, commaPos - startPos);
        tempID = stoi(numStr);

        startPos = commaPos + 1;
        commaPos = line.find(",", startPos);
        numStr = line.substr(startPos, commaPos - startPos);
        x = stod(numStr);

        startPos = commaPos + 1;
        commaPos = line.find(",", startPos);
        numStr = line.substr(startPos, commaPos - startPos);
        y = stod(numStr);

        startPos = commaPos + 1;
        commaPos = line.find(",", startPos);
        numStr = line.substr(startPos, commaPos - startPos);
        tempQuality = stoi(numStr);

        startPos = commaPos + 1;
        numStr = line.substr(startPos);
        spawnTime = stoi(numStr);

        Food newFood = Food(tempID, x, y, tempQuality, spawnTime);
        
        if (newFood.getSpawnTime() > 0){
            noOfExtraFoods++;
            extraFoodArr[extraIndex] = newFood;
            extraIndex++;
        }
        else{
            noOfAvailableFoods++;
            availFoodArr[availIndex] = newFood;
            availIndex++;
        }
    }
    orderID(creatures, noOfCreatures);
    //cout<<"----------------"<<endl;
    //availableFoods.display();
    arrayToQueueSpawnTime(extraFoods, extraFoodArr, noOfExtraFoods);
    arrayToQueueFoodQualify(availableFoods, availFoodArr, noOfAvailableFoods);
    //cout<<"----------------"<<endl;
    //availableFoods.display();
    int time = 0;
    
    //time steps
    while(!allCreaturesDead(creatures,noOfCreatures)){
        //cout<<time<<endl;
        //Current locations of all creatures should be printed
        printCreatures(creatures, noOfCreatures);
    
        //New food resources should be added (if any)
        addFood(extraFoods,availableFoods, time);
        
        //Fights between creatures should be resolved (if any)
        resolveFights(creatures, noOfCreatures);
        
        //Creatures should consume the best food if it is nearby
        for(int i = 0; i < noOfCreatures && !availableFoods.pqIsEmpty(); i++){
            creatures[i].consumeFood(availableFoods);
        }
        for(int i = 0; i < noOfCreatures && !availableFoods.pqIsEmpty(); i++){
            moveToBestFood(availableFoods, creatures[i]);
        }
        
        //Health of each creature should decrease by 1
        for(int i = 0; i < noOfCreatures; i++){
            creatures[i].decreaseHealth();
        }
        
        time++;
    }
    return 0;
}

