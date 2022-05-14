#ifndef TREEAMERICAN_H
#define TREEAMERICAN_H

#include "TreeProducts.h"
#include "PayOffBridge.h"

class TreeAmerican: public TreeProduct {
    public:
        TreeAmerican(double FinalTime_, const PayOffBridge& thePayOff_);
        virtual double FinalPayOff(double Spot) const;
        virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const;
        virtual TreeProduct* clone() const;
        virtual ~TreeAmerican() {};

    private:
        PayOffBridge thePayOff;
};

#endif