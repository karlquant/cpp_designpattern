/*
Requires
PayOff3.cpp
PayOffBridge.cpp
Random1.cpp
SimpleMC4.cpp
Vanilla3.cpp
*/

#include "SimpleMC6.h"
#include <iostream>

using namespace std;

int main(){

    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberofPaths;

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

    cout << "\nEnter NumberofPaths\n";
    cin >> NumberofPaths;

    ParametersConstant VolParam(Vol);
    ParametersConstant RParam(r);

    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);
    double result = SimpleMonteCarlo6(theOption, Spot, VolParam, RParam, NumberofPaths);
    cout << "the price of theOption is " << result << "\n";
    
    VanillaOption secondOption(theOption);
    result = SimpleMonteCarlo6(secondOption, Spot, VolParam, RParam, NumberofPaths);
    cout << "the price of secondOption is " << result << "\n";

    PayOffPut putPayOff(Strike);
    VanillaOption thirdOption(putPayOff, Expiry);
    result = SimpleMonteCarlo6(thirdOption, Spot, VolParam, RParam, NumberofPaths);
    cout << "the price of thirdOption is " << result << "\n";
    
    theOption = thirdOption;
    result = SimpleMonteCarlo6(theOption, Spot, VolParam, RParam, NumberofPaths);
    cout << "the price of theOption is " << result << "\n";

    // Just to avoid the windows close 
    double tmp;
    cin >> tmp;
    return 0;

}