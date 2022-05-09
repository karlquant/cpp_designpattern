#include "Vanilla1.h"

VanillaOption::VanillaOption(PayOff& thePayOff_, double Expiry_): thePayOff(thePayOff_), Expiry(Expiry_) {

}

double VanillaOption::GetExpiry() const {
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const {
    return thePayOff(Spot);
    
}