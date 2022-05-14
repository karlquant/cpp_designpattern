#include "TreeAmerican.h"
#include <algorithm>

using namespace std;

TreeAmerican::TreeAmerican(double FinalTime_, const PayOffBridge& thePayOff_): TreeProduct(FinalTime_), thePayOff(thePayOff_) {

}

TreeProduct* TreeAmerican::clone() const {
    return new TreeAmerican(*this);
}

double TreeAmerican::FinalPayOff(double Spot) const {
    return thePayOff(Spot);
}

double TreeAmerican::PreFinalValue(double Spot, double, double DiscountedFutureValue) const {
    return max(thePayOff(Spot), DiscountedFutureValue);

}