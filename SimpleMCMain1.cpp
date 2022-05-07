// Requires Random1.cpp

#include "Random1.h"
#include <iostream>
#include <cmath>
using namespace std;

double SimpleMonteCarlo1(double Expiry, double Strike, double Spot, double Vol, double r, unsigned long NumberofPaths) {
    double Variance = Vol * Vol * Expiry;
    double rootVariance = sqrt(Variance);
    double itoCorrection = -0.5*Variance;

    double movedSpot = Spot*exp(r*Expiry + itoCorrection);
    double thisSpot;
    double runningSum=0;

    for (unsigned long i=1; i < NumberofPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance*thisGaussian);
        double thisPayoff = thisSpot - Strike;
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberofPaths;
    mean *= exp(-r*Expiry);
    return mean;
}


int main() {
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

    double result = SimpleMonteCarlo1(Expiry, Strike, Spot, Vol, r, NumberofPaths);

    cout << "the price is " << result << "\n";
    
    // Just to avoid the windows close 
    double tmp;
    cin >> tmp;

    return 0;
}