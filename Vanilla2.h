#ifndef VANILLA2_H
#define VANILLA2_H

#include "PayOff3.h"

class VanillaOption {
    public:
        VanillaOption(const PayOff& thePayOff_, double Expiry);
        VanillaOption(const VanillaOption& original);
        VanillaOption& operator=(const VanillaOption& original);
        ~VanillaOption();

        double GetExpiry() const;
        double OptionPayOff(double Spot) const;

    private:
        PayOff* thePayOffPtr;
        double Expiry;
};

#endif