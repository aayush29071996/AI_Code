//
// Created by Saswat Das on 09/10/17.
//

#include <iostream>

using namespace std;

int fourGallon = 0;
int threeGallon = 0;

int fillFourGallon(int);
int fillThreeGallon(int);
#define emptyFourGallon() fourGallon = 0
#define emptyThreeGallon() threeGallon = 0

void printJars();

int main () {
    cout<<"You are given two jugs, a 4-gallon one and a 3-gallon one, \na pump which has unlimited water which you can use to fill the jug, \nand the ground on which water may be poured\n";
    cout<<"You can perform 1(one) of the following operation at once\n\n";
    cout<<"1. Fill 4-gal jug\n2. Fill 3-gal jug\n3. Empty 4-gal jug on ground\n4. Empty 3-gal jug on ground\n5. Pour water from 3-gal jug to fill 4-gal jug\n6. Pour water from 4-gal jug to fill 3-gal-jug\n";
    cout<<"7. Pour all of water from 3-gal jug into 4-gal jug\n8. Pour all of water from 4-gal jug into 3-gal jug\n9: Quit\n\n";

    cout<<"Your target is to have 2 gallon water only in the 4 gallon Jar";
    while (!(fourGallon == 2 && threeGallon == 0)) {
        int intent;
        cout<<"What to do ?";
        cin>>intent;
        if (intent == 1) fillFourGallon(4); // If we fill with 4 it will for sure get filled
        if (intent == 2) fillThreeGallon(3); // If we fill with 3 it will get filled for sure
        if (intent == 3) emptyFourGallon();
        if (intent == 4) emptyThreeGallon();
        if (intent == 5) {
            if(threeGallon + fourGallon >= 4) {
                threeGallon-= (4 - fourGallon);
                fillFourGallon(4);
            } else {
                cout<< "Now enough water";
            }
        }
        if (intent == 6) {
            if(threeGallon + fourGallon >= 4) {
                fourGallon-= (3 - threeGallon);
                fillThreeGallon(3);
            } else {
                cout<< "Now enough water";
            }
        }
        if (intent == 7) {
            if(threeGallon + fourGallon <= 4) {
                fillFourGallon(threeGallon);
                emptyThreeGallon();
            } else {
                cout << "Too much water";
            }
        }
        if (intent == 8) {
            if(threeGallon + fourGallon <= 3) {
                fillThreeGallon(fourGallon);
                emptyFourGallon();
            } else {
                cout << "Too much water";
            }
        }
        if (intent == 9) break;
        printJars();
    }
    return 0;
}

void printJars() {
    cout<<"4-gal: "<<fourGallon<<"    "<<threeGallon<<":3-gal"<<endl;
}

int fillFourGallon(int amount) {
    return fourGallon = min(fourGallon+amount, 4);
}

int fillThreeGallon(int amount) {
    return threeGallon = min(threeGallon+amount, 3);
}