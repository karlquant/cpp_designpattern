#include "Vanilla3.h"

VanillaOption::VanillaOption(const PayOffBridge& thePayOff_, double Expiry_): thePayOff(thePayOff_), Expiry(Expiry_) {
    
}

double VanillaOption::GetExpiry() const{
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const {
    return thePayOff.operator()(Spot);
}

