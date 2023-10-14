//
//  Accompaniment.h
//  hw4
//
//  Created by Alper Bozkurt on 18.05.2023.
//

#ifndef Accompaniment_h
#define Accompaniment_h

#include <iostream>
#include <string>
#include <list>
#include "Snack.h"
using namespace std;
class Accompaniment {

public:
    Accompaniment(string name, Snack* snack1, Snack* snack2);

    string accompanimentName;
    Snack* snack1;
    Snack* snack2;

};

#endif /* Accompaniment_h */
