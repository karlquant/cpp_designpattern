#include "PathDependentAsian.h"

PathDependentAsian::PathDependentAsian(const valarray<double>& LookAtTimes_, double DeliveryTime_, const PayOffBridge& thePayOff_): PathDependent(LookAtTimes_), DeliveryTime(DeliveryTime_), thePayOff(thePayOff_), NumberOfTimes(LookAtTimes_.size()) {

}

unsigned long PathDependentAsian::MaxNumberOfCashFlows() const {
    return 1UL;
}

valarray<double> PathDependentAsian::PossibleCashFlowTimes() const {
    valarray<double> tmp(1UL);
    tmp[0] = DeliveryTime;
    return tmp;
}

unsigned long PathDependentAsian::CashFlows(const valarray<double>& SpotValues, vector<CashFlow>& GeneratedFlows) const {
    double sum = SpotValues.sum();
    double mean = sum / NumberOfTimes;
    GeneratedFlows[0].TimeIndex = 0UL;

    GeneratedFlows[0].Amount = thePayOff(mean);
    return 1UL;
}

PathDependent* PathDependentAsian::clone() const {
    return new PathDependentAsian(*this);
}

