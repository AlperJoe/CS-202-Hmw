//
//  AccompanimentHashing.h
//  hw4
//
//  Created by Alper Bozkurt on 18.05.2023.
//

#ifndef AccompanimentHashing_h
#define AccompanimentHashing_h

#include "Accompaniment.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;
class AccompanimentHashing {
private:
    static const int tableSize = 71;
    Accompaniment* hashTable[tableSize];
public:
    AccompanimentHashing();
    int hashFunction(string accompanimentName);
    Accompaniment* findAccompaniment(string accompanimentName);
    void insertAccompaniment(string accompanimentName, Snack* snack1, Snack* snack2);
};
#endif /* AccompanimentHashing_h */
