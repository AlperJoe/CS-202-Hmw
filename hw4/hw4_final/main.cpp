#include <iostream>
#include <string>
#include <list>
#include "Snack.h"
#include "SnackHashing.h"
#include "Accompaniment.h"
#include "AccompanimentHashing.h"

using namespace std;




int main(int argc, char* argv[]) {
    SnackHashing snackHashing;
    AccompanimentHashing accompanimentHashing;

    string command;
    bool loops = true;
    int i = 1;
    while (loops && i<argc) {
        //cout << "Enter command: ";
        //getline(cin, command);

        char first = argv[i][1];
        if (first == 'X') {
            loops = false;
            break;
        }
        /*string rest = command.substr(2);*/
        string second = argv[i+1];
        string third = "";

        switch (first) {
        case 'S':
            snackHashing.insertSnack(second);
            cout << "Snack '" << second << "' created" << endl;
            i = i + 2;
            break;

        case 'C': {
            third = argv[i + 2];
            string snack1 = second;
            string snack2 = third;

            string accompanimentName;
            if (snack1 < snack2) {
                accompanimentName = snack1 + snack2;
            }
            else {
                accompanimentName = snack2 + snack1;
            }
            Snack* s1 = snackHashing.findSnack(snack1);
            Snack* s2 = snackHashing.findSnack(snack2);
            snackHashing.addAccompaniment(snack1, snack2);
            accompanimentHashing.insertAccompaniment(accompanimentName, s1, s2);
            i = i + 3;
            break;
        }
        case 'D': {
            third = argv[i + 2];
            string snack1 = second;
            string snack2 = third;
            string accompanimentName;
            if (snack1 < snack2) {
                accompanimentName = snack1 + snack2;
            }
            else {
                accompanimentName = snack2 + snack1;
            }


            snackHashing.removeAccompaniment(snack1, snack2);
            accompanimentHashing.removeAccompaniment(accompanimentName);
            i = i + 3;
            break;
        }
        case 'L':
            snackHashing.printAccompaniments(second);
            i = i + 2;
            break;

        case 'Q': {
            third = argv[i + 2];
            string snack1 =second;
            string snack2 =third;
            string accompanimentName;
            if (snack1 < snack2) {
                accompanimentName = snack1 + snack2;
            }
            else {
                accompanimentName = snack2 + snack1;
            }
            Accompaniment* accompaniment = accompanimentHashing.findAccompaniment(accompanimentName);
            if (accompaniment != nullptr) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            i = i + 3;
            break;
        }

        }

    }
            return 0;
}