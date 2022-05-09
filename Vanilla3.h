#ifndef VANILLA3_H
#define VANILLA3_H

#include "PayOffBridge.h"

class VanillaOption {
    public:
        VanillaOption(const PayOffBridge& thePayOff_, double Expiry);
        // VanillaOption(const VanillaOption& original);
        // VanillaOption& operator=(const VanillaOption& original);
        // ~VanillaOption();

        double GetExpiry() const;
        double OptionPayOff(double Spot) const;

    private:
        PayOffBridge thePayOff;
        double Expiry;
};

#endif