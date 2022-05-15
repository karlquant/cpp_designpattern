/*
Requires
BlackScholesFormulas.cpp
BSCallClass2.cpp
BSCall.cpp
Normals.cpp
*/

#include "NewtonRaphson.h"
#include "Bisection.h"
#include "BSCallClass.h"
#include "BSCallClass2.h"
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    double d;
    double tolerance;
    

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

    cout << "\nEnter tolerance\n";
    cin >> tolerance;

    BSCall bsCall(r, d, Expiry, Spot, Strike);

    double price = bsCall(Vol);
    cout << "\n Price : " << price;

    double solver_vol = Bisection(price, 0.1, 10.0, tolerance, bsCall);
    cout << "\n Vol: Bisection : " << solver_vol;
    double price2 = bsCall(solver_vol);
    cout << "\n Price2 : " << price2;

    BSCallTwo bsCallTwo(r, d, Expiry, Spot, Strike);

    double solver_vol2 = NewtonRaphson<BSCallTwo, &BSCallTwo::Price, &BSCallTwo::Vega>(price, 0.1, tolerance, bsCallTwo);

    cout  << " \n NewtonRaphson : " << solver_vol2 << "\n";
    double price3 = bsCall(solver_vol2);
    cout << "\n Price3 : " << price3;



    double tmp;
    cin >> tmp;

    return 0;
}