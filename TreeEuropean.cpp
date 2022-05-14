#include "TreeEuropean.h"

TreeEuropean::TreeEuropean(double FinalTime_, const PayOffBridge& thePayOff_): TreeProduct(FinalTime_), thePayOff(thePayOff_) {

}

TreeProduct* TreeEuropean::clone() const {
    return new TreeEuropean(*this);
}

double TreeEuropean::FinalPayOff(double Spot) const {
    return thePayOff(Spot);
}

double TreeEuropean::PreFinalValue(double, double, double DiscountedFutureValue) const {
    return DiscountedFutureValue;
}