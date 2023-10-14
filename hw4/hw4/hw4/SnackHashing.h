//
//  SnackHashing.h
//  hw4
//
//  Created by Alper Bozkurt on 17.05.2023.
//

#ifndef SnackHashing_h
#define SnackHashing_h
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include "Snack.h"

class SnackHashing {
private:
    static const int tableSize = 11;
    list<Snack*> hashTable[tableSize];
    int hashFunction(string name);

public:
    SnackHashing();

    void insertSnack(string name);
   
    Snack* findSnack(string name);

    void addAccompaniment(string snack1, string snack2);

    void removeAccompaniment(string snack1, string snack2);
    void printAccompaniments(string snack);
};


#endif /* SnackHashing_h */
