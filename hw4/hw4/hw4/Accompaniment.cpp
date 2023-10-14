//
//  Accompaniment.cpp
//  hw4
//
//  Created by Alper Bozkurt on 18.05.2023.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include "Accompaniment.h"

using namespace std;
Accompaniment::Accompaniment(string name, Snack* snack1, Snack* snack2) {
       this->accompanimentName = name;
       this->snack1 = snack1;
       this->snack2 = snack2;
}
