//
//  Snack.h
//  hw4
//
//  Created by Alper Bozkurt on 17.05.2023.
//

#ifndef Snack_h
#define Snack_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Snack {
public:
    string name;
    list<Snack*> accompaniments;
    Snack(string name);
};

#endif /* Snack_h */
