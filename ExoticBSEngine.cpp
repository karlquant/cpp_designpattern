#include "ExoticBSEngine.h"
#include <cmath>

using namespace std;

ExoticBSEngine::ExoticBSEngine(const Wrapper<PathDependent>& theProduct, const Parameters& R_, const Parameters& D_, const Parameters& Vol_, const Wrapper<RandomBase>& theGenerator_, double Spot): ExoticEngine(theProduct, R_), theGenerator(theGenerator_) {
    valarray<double> Times(theProduct->GetLookAtTimes());
    NumberOfTimes = Times.size();

    theGenerator->ResetDimensionality(NumberOfTimes);
    Drifts.resize(NumberOfTimes);
    StandardDeviations.resize(NumberOfTimes);

    double variance = Vol_.IntegralSquare(0, Times[0]);
    Drifts[0] = R_.Integral(0, Times[0]) - D_.Integral(0, Times[0]) - 0.5*variance;
    StandardDeviations[0] = sqrt(variance);

    for (unsigned long i=1; i < NumberOfTimes; i++) {
        variance = Vol_.IntegralSquare(Times[i-1], Times[i]);
        Drifts[i] = R_.Integral(Times[i-1], Times[i]) - D_.Integral(Times[i-1], Times[i]) - 0.5 * variance;
        StandardDeviations[i] = sqrt(variance);
    }

    logSpot = log(Spot);
    variates.resize(NumberOfTimes);
}

void ExoticBSEngine::GetOnePath(valarray<double>& SpotValues) {
    theGenerator->GetGaussians(variates);

    double CurrentLogSpot = logSpot;

    for (unsigned long i=0; i < NumberOfTimes; i++) {
        CurrentLogSpot += Drifts[i];
        CurrentLogSpot += StandardDeviations[i] * variates[i];
        SpotValues[i] = exp(CurrentLogSpot);
    }

    return;
}