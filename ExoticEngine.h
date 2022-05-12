#ifndef EXOTICENGINE_H
#define EXOTICENGINE_H

#include "Wrapper.h"
#include "Parameters.h"
#include "PathDependent.h"
#include "StatisticsMC.h"
#include <vector>

using namespace std;

class ExoticEngine {
    public:
        ExoticEngine(const Wrapper<PathDependent>& theProduct_, const Parameters& r_);

        virtual void GetOnePath(valarray<double>& SpotValues)=0;
        virtual void DoSimulation(StatisticsMC& theGatherer, unsigned long NumberOfPaths);
        double DoOnePath(const valarray<double>& SpotValues) const;

        virtual ~ExoticEngine() {};

    private:
        Wrapper<PathDependent> theProduct;
        Parameters r;
        valarray<double> Discounts;
        mutable vector<CashFlow> theseCashFlows;
};

#endif