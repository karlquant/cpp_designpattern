/*
Requires 
DoubleDigital.cpp
PayOff2.cpp
Random1.cpp
SimpleMC3.cpp
Vanilla1.cpp
*/

#include "SimpleMC3.h"
#include "DoubleDigital.h"
#include "Vanilla1.h"

#include <iostream>

using namespace std;

int main() {
    double Expiry;
    double Low, Up;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nEnter Expiry\n";
    cin >> Expiry;

    cout << "\nEnter lower barrier\n";
    cin >> Low;

    cout << "\nEnter upper barrier\n";
    cin >> Up;

    cout << "\nEnter Spot\n";
    cin >> Spot;

    cout << "\nEnter Vol\n";
    cin >> Vol;

    cout << "\nEnter r\n";
    cin >> r;

    cout << "\nEnter NumberOfPaths\n";
    cin >> NumberOfPaths;

    PayOffDoubleDigital thePayOff(Low, Up);
    VanillaOption theOption(thePayOff, Expiry);

    double result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);

    cout << "\nthe price is " << result << "\n";

    double tmp;
    cin >> tmp;

    return 0;
}
