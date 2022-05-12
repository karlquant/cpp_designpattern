/*
Requires
AntiThetic.cpp
ConvergenceTable.cpp
ExoticBSEngine.cpp
ExoticEngine.cpp
StatisticsMC.cpp
Normals.cpp
Parameters.cpp
ParkMiller.cpp
PathDependent.cpp
PathDependentAsian.cpp
PayOff3.cpp
PayOffBridge.cpp
Random3.cpp
*/

#include "ParkMiller.h"
#include <iostream>
using namespace std;
#include "StatisticsMC.h"
#include "ConvergenceTable.h"
#include "AntiThetic.h"
#include "PathDependentAsian.h"
#include "ExoticBSEngine.h"

int main() {


    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    double d;
    unsigned long NumberofDates;
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

    cout << "\nEnter d\n";
    cin >> d;

    cout << "\nEnter NumberofDates\n";
    cin >> NumberofDates;

    cout << "\nEnter NumberofPaths\n";
    cin >> NumberofPaths;

    ParametersConstant VolParam(Vol);
    ParametersConstant RParam(r);
    ParametersConstant DParam(d);

    PayOffCall thePayOff(Strike);

    valarray<double> Times;
    Times.resize(NumberofDates);
    
    for (unsigned long i=0; i < NumberofDates; i++) {
        Times[i] = (i + 1.0) / NumberofDates * Expiry;
    }

    PathDependentAsian theOption(Times, Expiry, thePayOff);    
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    RandomParkMiller generator(NumberofDates);
    AntiThetic genTwo(generator);

    ExoticBSEngine theEngine(theOption, RParam, DParam, VolParam, genTwo, Spot);
    theEngine.DoSimulation(gathererTwo, NumberofPaths);

    vector<vector<double>> reuslts = gathererTwo.GetResultsSoFar();

    cout << "\nthe call price the results are \n";

    for (unsigned long i = 0; i < reuslts.size(); i++) {
        for (unsigned long j =0; j < reuslts[i].size(); j++) {
            cout << "\n" << reuslts[i][j];
        }
    }

    double tmp;
    cin >> tmp;

    return 0;

}