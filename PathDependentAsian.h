#ifndef PATHDEPENDENTASIAN_H
#define PATHDEPENDENTASIAN_H


#include "PathDependent.h"
#include "PayOffBridge.h"

class PathDependentAsian: public PathDependent {
    public:
        PathDependentAsian(const valarray<double>& LookAtTimes_, double DeliveryTime_, const PayOffBridge& thePayOff_);

        virtual unsigned long MaxNumberOfCashFlows() const;
        virtual valarray<double> PossibleCashFlowTimes() const;
        virtual unsigned long CashFlows(const valarray<double>& SpotValues, vector<CashFlow>& GeneratedFlows) const;
        virtual PathDependent* clone() const;

        virtual ~PathDependentAsian() {};

    private:
        double DeliveryTime;
        PayOffBridge thePayOff;
        unsigned long NumberOfTimes;
};

#endif