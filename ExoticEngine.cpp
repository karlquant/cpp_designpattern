#include "ExoticEngine.h"
#include <cmath>

ExoticEngine::ExoticEngine(const Wrapper<PathDependent>& theProduct_, const Parameters& r_): theProduct(theProduct_), r(r_) {
    Discounts = theProduct->PossibleCashFlowTimes();
    for (unsigned long i=0; i < Discounts.size(); i++){
        Discounts[i] = exp(-r.Integral(0, Discounts[i]));
    }

    theseCashFlows.resize(theProduct->MaxNumberOfCashFlows());

}

void ExoticEngine::DoSimulation(StatisticsMC& theGatherer, unsigned long NumberOfPaths) {
    valarray<double> SpotValues(theProduct->GetLookAtTimes());

    theseCashFlows.resize(theProduct->MaxNumberOfCashFlows());
    double thisValue;

    for (unsigned long i=0; i < NumberOfPaths; i++) {
        GetOnePath(SpotValues);
        thisValue = DoOnePath(SpotValues);
        theGatherer.DumpOneResult(thisValue);
    }

    return;
}

double ExoticEngine::DoOnePath(const valarray<double>& SpotValues) const{
    unsigned long NumberFlows = theProduct->CashFlows(SpotValues, theseCashFlows);
    double value = 0.0;

    for (unsigned long i=0; i < NumberFlows; i++) {
        value += theseCashFlows[i].Amount * Discounts[theseCashFlows[i].TimeIndex];
    }

    return value;
}