//
//  SnackHashing.cpp
//  hw4
//
//  Created by Alper Bozkurt on 17.05.2023.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include "Snack.h"
#include "SnackHashing.h"

using namespace std;


int SnackHashing::hashFunction(string name) {
    int sum = 0;
    for (char c : name) {
        sum += int(c);
    }
    return sum % tableSize;
}


SnackHashing::SnackHashing() {
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = {};
    }
}

void SnackHashing::insertSnack(string name) {
    int index = hashFunction(name);
    Snack* newSnack = new Snack(name);
    hashTable[index].push_front(newSnack);
}


Snack* SnackHashing::findSnack(string name) {
    int index = hashFunction(name);
    for (Snack* s : hashTable[index]) {
        if (s->name == (name)) {
            return s;
        }
    }
    return nullptr;
}

void SnackHashing::addAccompaniment(string snack1, string snack2) {
    if (snack1 == snack2) return;  // if the snacks are the same, do nothing

    Snack* s1 = findSnack(snack1);
    Snack* s2 = findSnack(snack2);
    if (s1 != nullptr && s2 != nullptr) {
        s1->accompaniments.push_front(s2);
        s2->accompaniments.push_front(s1);
    }
}

void SnackHashing::removeAccompaniment(string snack1, string snack2) {
    Snack* s1 = findSnack(snack1);
    Snack* s2 = findSnack(snack2);
    if (s1 != nullptr && s2 != nullptr) {
        s1->accompaniments.remove(s2);
        s2->accompaniments.remove(s1);
    }
}
void SnackHashing::printAccompaniments(string snack) {
    Snack* s = findSnack(snack);
    if (s != nullptr) {
        for (Snack* accompaniment : s->accompaniments) {
            cout << accompaniment->name << " ";
        }
        cout << endl;
    }
}
