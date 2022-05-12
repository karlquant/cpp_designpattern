#ifndef PATHDEPENDENT_H
#define PATHDEPENDENT_H

#include <valarray>
#include <vector>

using namespace std;

class CashFlow {
    public:
        unsigned long TimeIndex;
        double Amount;
        CashFlow(unsigned long TimeIndex_=0UL, double Amount_=0.0): TimeIndex(TimeIndex_), Amount(Amount_) {};

    private:
};

class PathDependent {
    public:
        PathDependent(const valarray<double>& LookAtTimes);
        const valarray<double>& GetLookAtTimes() const;
        virtual unsigned long MaxNumberOfCashFlows() const=0;
        virtual valarray<double> PossibleCashFlowTimes() const=0;

        virtual unsigned long CashFlows(const valarray<double>& SpotValues, vector<CashFlow>& GeneratedFlows) const=0;
        virtual PathDependent* clone() const=0;
        virtual ~PathDependent() {};

    private:
        valarray<double> LookAtTimes;
};

#endif