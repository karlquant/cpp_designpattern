/*
Requires 
PayOff2.cpp
Random1.cpp
SimpleMC2.cpp

*/

#include "SimpleMC2.h"
#include <iostream>
using namespace std;

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nEnter Expiry\n";
    cin >> Expiry;

    cout << "\nEnter Strike\n";
    cin >> Strike;

    cout << "\nEnter Spot\n";
    cin >> Spot;

    cout << "\nEnter Vol\n";
    cin >> Vol;

    cout << "\nEnter r\n";
    cin >> r;

    cout << "\nEnter NumberOfPaths\n";
    cin >> NumberOfPaths;

    unsigned long theOptionType;
    cout << "\nOption Type\n";
    cin >> theOptionType;

    PayOff* thePayOffPtr;

    if (theOptionType == 0) {
        thePayOffPtr = new PayOffCall(Strike);
    }
    else {
        thePayOffPtr = new PayOffPut(Strike);
    }

    

    double result = SimpleMonteCarlo2(*thePayOffPtr, Expiry, Spot, Vol, r, NumberOfPaths);
    string optiontype = (theOptionType == 0) ? "call" : "put";

    cout << "the price of " << optiontype << " is " << result << "\n";


    double tmp;
    cin >> tmp;

    delete thePayOffPtr;

    return 0;


}