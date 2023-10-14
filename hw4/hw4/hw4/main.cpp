#include <iostream>
#include <string>
#include <list>
#include "Snack.h"
#include "SnackHashing.h"
#include "Accompaniment.h"
#include "AccompanimentHashing.h"

using namespace std;

int main() {
    SnackHashing snackHashing;
    AccompanimentHashing accompanimentHashing;

    string command;
    bool loops = true;
    while (loops) {
        getline(cin, command);

        char first = command[0];
        string rest = command.substr(2);

        switch (first) {
            case 'S':
                snackHashing.insertSnack(rest);
                cout<<"Snack '"<<rest<<"' created"<<endl;
                break;
                
            case 'C': {
                size_t spaceIndex = rest.find(' ');
                string snack1 = rest.substr(0, spaceIndex);
                string snack2 = rest.substr(spaceIndex + 1);
                
                string accompanimentName;
                if(snack1 < snack2){
                    accompanimentName = snack1 + snack2;
                }
                else{
                    accompanimentName = snack2 + snack1;
                }
                Snack* s1 = snackHashing.findSnack(snack1);
                Snack* s2 = snackHashing.findSnack(snack2);
                snackHashing.addAccompaniment(snack1, snack2);
                accompanimentHashing.insertAccompaniment(accompanimentName, s1, s2);
                break;
            }
            case 'D': {
                size_t spaceIndex = rest.find(' ');
                string snack1 = rest.substr(0, spaceIndex);
                string snack2 = rest.substr(spaceIndex + 1);
                
                snackHashing.removeAccompaniment(snack1, snack2);
                break;
            }
            case 'L':
                snackHashing.printAccompaniments(rest);
                break;
                
            case 'Q': {
                size_t spaceIndex = rest.find(' ');
                string snack1 = rest.substr(0, spaceIndex);
                string snack2 = rest.substr(spaceIndex + 1);
                string accompanimentName;
                if(snack1 < snack2){
                    accompanimentName = snack1 + snack2;
                }
                else{
                    accompanimentName = snack2 + snack1;
                }
                Accompaniment* accompaniment = accompanimentHashing.findAccompaniment(accompanimentName);
                if (accompaniment != nullptr) {
                    cout << "Yes" << endl;
                }
                else {
                    cout << "No" << endl;
                }
                break;
            }
            case 'X':
                loops = false;
                return 0;
        }
    }
}
