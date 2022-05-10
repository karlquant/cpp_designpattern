#include "ConvergenceTable.h"

ConvergenceTable::ConvergenceTable(const Wrapper<StatisticsMC>& inner_): inner(inner_) {
    stoppingPoint = 2;
    PathsDone = 0;
}

StatisticsMC* ConvergenceTable::clone() const{
    return new ConvergenceTable(*this);
}

void ConvergenceTable::DumpOneResult(double result) {
    inner->DumpOneResult(result);
    PathsDone++;

    if (PathsDone == stoppingPoint) {
        stoppingPoint *= 2;
        std::vector<std::vector<double>> thisResult(inner->GetResultsSoFar());

        for (unsigned long i=0; i < thisResult.size(); i++) {
            thisResult[i].push_back(PathsDone);
            resultsSoFar.push_back(thisResult[i]);
        }

    }
    return;
}

std::vector<std::vector<double>> ConvergenceTable::GetResultsSoFar() const {
    std::vector<std::vector<double>> tmp(resultsSoFar);
    if (PathsDone*2 != stoppingPoint) {
        std::vector<std::vector<double>> thisResult(inner->GetResultsSoFar());
        for (unsigned long i=0; i < thisResult.size(); i++) {
            thisResult[i].push_back(PathsDone);
            tmp.push_back(thisResult[i]);
        }

        
    }
    return tmp;
}