#ifndef TREEEUROPEAN_H
#define TREEEUROPEAN_H


#include "TreeProducts.h"
#include "PayOffBridge.h"

class TreeEuropean: public TreeProduct {
    public:
        TreeEuropean(double FinalTime_, const PayOffBridge& thePayOff_);
        virtual double FinalPayOff(double Spot) const;
        virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const;
        virtual TreeProduct* clone() const;

        virtual ~TreeEuropean() {};

    private:
        PayOffBridge thePayOff;
};

#endif