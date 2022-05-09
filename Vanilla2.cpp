#include "Vanilla2.h"

VanillaOption::VanillaOption(const PayOff& thePayOff_, double Expiry_): Expiry(Expiry_) {
    thePayOffPtr = thePayOff_.clone();
}

double VanillaOption::GetExpiry() const {
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const {
    return (*thePayOffPtr)(Spot);
}

VanillaOption::VanillaOption(const VanillaOption& original) {
    Expiry = original.Expiry;
    thePayOffPtr = original.thePayOffPtr->clone();
}

VanillaOption& VanillaOption::operator=(const VanillaOption& original) {
    if (this != &original) {
        Expiry = original.Expiry;
        delete thePayOffPtr;
        thePayOffPtr = original.thePayOffPtr->clone();
    }
    return *this;
}

VanillaOption::~VanillaOption() {
    delete thePayOffPtr;
}