/*
Requires
BinominalTree.cpp
BlackScholesFormulas.cpp
Normals.cpp
Parameters.cpp
PayOff3.cpp
PayOffBridge.cpp
PayOffForward.cpp
TreeAmerican.cpp
TreeProducts.cpp
TreeEuropean.cpp

*/

#include "BinomialTree.h"
#include "PayOff3.h"
#include <iostream>
#include "TreeProducts.h"
#include "TreeAmerican.h"
#include "TreeEuropean.h"
using namespace std;

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    double d;
    unsigned long NumberofSteps;

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

    cout << "\nEnter d\n";
    cin >> d;

    cout << "\nEnter NumberofSteps\n";
    cin >> NumberofSteps;

    
    ParametersConstant RParam(r);
    ParametersConstant DParam(d);

    PayOffCall thePayOff(Strike);

    TreeAmerican treeA(Expiry, thePayOff);
    TreeEuropean treeE(Expiry, thePayOff);

    SimpleNominalTree simpleTree(Spot, RParam, DParam, Vol, NumberofSteps, Expiry);

    double result = simpleTree.GetThePrice(treeA);

    cout << "TreeAmerican call option result " << result << "\n";
    
    result = simpleTree.GetThePrice(treeE);

    cout << "TreeEuropean call option result " << result << "\n";

    double tmp;
    cin >> tmp;

    return 0;
}