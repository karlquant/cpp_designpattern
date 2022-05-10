/* 
Requires
StatisticMC.cpp
Parameters.cpp
PayOff3.cpp
PayOffBridge.cpp
Random1.cpp
SimpleMC7.cpp
Vanilla3.cpp
*/

#include "SimpleMC7.h"
#include <iostream>

using namespace std;

#include "Vanilla3.h"
#include "StatisticsMC.h"
#include "ConvergenceTable.h"

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

    SimpleMonteCarlo7(theOption, Spot, VolParam, RParam, NumberofPaths, gathererTwo);

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