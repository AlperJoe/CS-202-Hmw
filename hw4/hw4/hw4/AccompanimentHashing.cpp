//
//  AccompanimentHashing.cpp
//  hw4
//
//  Created by Alper Bozkurt on 18.05.2023.
//

#include <stdio.h>
#include "AccompanimentHashing.h"
#include "Accompaniment.h"
#include <iostream>
#include <string>
#include <list>


AccompanimentHashing::AccompanimentHashing() {
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = nullptr;
    }
}

int AccompanimentHashing::hashFunction(string accompanimentName) {
    int sum = 0;
    for (char c : accompanimentName) {
        sum += int(c);
    }
    return sum % tableSize;
}

void AccompanimentHashing::insertAccompaniment(string accompanimentName, Snack* snack1, Snack* snack2){
    Accompaniment* newAccompaniment = new Accompaniment(accompanimentName,snack1,snack2);
    int index = hashFunction(accompanimentName);
    int i = 0;
    while (hashTable[index] != nullptr) {
        index = (index + i * i) % tableSize;
        i++;
    }
    hashTable[index] = newAccompaniment;
}

Accompaniment* AccompanimentHashing::findAccompaniment(string accompanimentName) {
    int index = hashFunction(accompanimentName);
    int i = 0;
    while (hashTable[index] != nullptr) {
        if (hashTable[index]->accompanimentName == accompanimentName) {
            return hashTable[index];
        }
        index = (index + i * i) % tableSize;
        i++;
    }
    return nullptr;
}
