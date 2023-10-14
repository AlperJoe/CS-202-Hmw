/**
* Title: Binary Search Trees
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 2
* Description : Analysis class for measure time in the process of
 inserting and deleting element time and display it.
 */
#include <stdio.h>
#include "analysis.h"
#include  "BST.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>


using namespace std;
using namespace chrono;

void timeAnalysis(){
    BST tree;
    const int arraySize = 15000;
    const int elapsedSize = 1500;
    int* arr = new int[arraySize];
    
    cout << "Part e - Time analysis of Binary Search Tree - part 1" << endl;
    cout << "-----------------------------------------------------" << endl;
    printf("%-10s %-10s \n", "Tree Size", "Time Elapsed");
    cout << "-----------------------------------------------------" << endl;
    
    clock_t start;
    clock_t end;
    //creates random array measuring time while inserting
    for(int index = 0; index < arraySize; index++){
        
        if((index + 1) % elapsedSize == 1){
            start = clock();
        }
        arr[index] = rand() % arraySize; //random number in range 0 to array size
        tree.insertItem(arr[index]);
        
        if((index + 1) % elapsedSize == 0){
            end = clock();
            double duration = double(end - start) * 1000/ CLOCKS_PER_SEC ;
            printf("%-10d %-10f %s\n",index+1,duration,"ms");
        }
    }
    
    cout<<endl;
    
    cout << "Part e - Time analysis of Binary Search tree - part 2" << endl;
    cout << "-----------------------------------------------------" << endl;
    printf("%-10s %-10s \n", "Tree Size", "Time Elapsed");
    cout << "-----------------------------------------------------" << endl;
    
    
    //shuffle the array
    for(int j = 0; j < arraySize; j++){
        int k = rand() % arraySize;  //random number in range 0 to array size
        
        int temp = arr[j];
        arr[j] = arr[k];
        arr[k] = temp;
    }
    
    for(int i = 0 ; i < arraySize; i++){
        if((i + 1) % elapsedSize == 1){
            start = clock();
        }
        tree.deleteItem(arr[i]);
        
        if((i + 1) % elapsedSize == 0){
            end = clock();
            double duration = double(end - start) * 1000 / CLOCKS_PER_SEC ;
            printf("%-10d %-10f %s\n",arraySize - (i+1),duration, "ms");
        }
    }
}
