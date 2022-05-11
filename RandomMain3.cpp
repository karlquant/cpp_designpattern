/*
Requires 
AntiThetic.cpp
ConvergenceTable.cpp
StatitsicsMC.cpp
Normals.cpp
Parameters.cpp
ParkMiller.cpp
PayOff3.cpp
Random2.cpp
SimpleMC8.cpp
Vanilla3.cpp

*/

#include "SimpleMC8.h"
#include "ParkMiller.h"
#include <iostream>

using namespace std;
#include "Vanilla3.h"
#include "StatisticsMC.h"
#include "ConvergenceTable.h"
#include "AntiThetic.h"


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

    ParametersConstant VolParam(Vol);
    ParametersConstant RParam(r);

    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);    
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

    RandomParkMiller generator(1);

    SimpleMonteCarlo8(theOption, Spot, VolParam, RParam, NumberofPaths, gathererTwo, generator);

    vector<vector<double>> reuslts = gathererTwo.GetResultsSoFar();

    cout << "\nthe call price the results are \n";

    for (unsigned long i = 0; i < reuslts.size(); i++) {
        for (unsigned long j =0; j < reuslts[i].size(); j++) {
            cout << "\n" << reuslts[i][j];
        }
    }

    AntiThetic generatorTwo(generator);
    ConvergenceTable gathererThree(gatherer);
    SimpleMonteCarlo8(theOption, Spot, VolParam, RParam, NumberofPaths, gathererThree, generatorTwo);

    vector<vector<double>> reusltsTwo = gathererThree.GetResultsSoFar();

    cout << "\nthe call price the results are \n";

    for (unsigned long i = 0; i < reusltsTwo.size(); i++) {
        for (unsigned long j =0; j < reusltsTwo[i].size(); j++) {
            cout << "\n" << reusltsTwo[i][j];
        }
    }

    double tmp;
    cin >> tmp;

    return 0;
}