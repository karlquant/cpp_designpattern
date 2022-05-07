/*
Requires
DoubleDigital.cpp
Random1.cpp

*/

#include "SimpleMC2.h"
#include "DoubleDigital.h"
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

    double result = SimpleMonteCarlo2(thePayOff, Expiry, Spot, Vol, r, NumberOfPaths);

    
    cout << "the price of DoubleDigital  is " << result << "\n";


    double tmp;
    cin >> tmp;

    return 0;


}