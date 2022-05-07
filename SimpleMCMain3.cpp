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

    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);

    double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);

    cout << "the price of call is " << resultCall << "\n";

    double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Spot, Vol, r, NumberOfPaths);

    cout << "the price of put is " << resultPut << "\n";

    double tmp;
    cin >> tmp;

    return 0;


}