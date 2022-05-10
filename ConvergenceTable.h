#ifndef CONVERGENCETABLE_H
#define CONVERGENCETABLE_H

#include "StatisticsMC.h"
#include "Wrapper.h"

class ConvergenceTable : public StatisticsMC {
    public: 
        ConvergenceTable(const Wrapper<StatisticsMC>& inner_);
        virtual StatisticsMC* clone() const;
        virtual void DumpOneResult(double result);
        virtual std::vector<std::vector<double>> GetResultsSoFar() const;

    private:
        Wrapper<StatisticsMC> inner;
        std::vector<std::vector<double>> resultsSoFar;
        unsigned long stoppingPoint;
        unsigned long PathsDone;
};



#endif