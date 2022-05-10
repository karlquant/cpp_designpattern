#include "StatisticsMC.h"

using namespace std;

StatisticsMean::StatisticsMean() {
    runningSum = 0.0;
    PathsDone = 0UL;
}

void StatisticsMean::DumpOneResult(double result) {
    PathsDone++;
    runningSum += result;
}

vector<vector<double>> StatisticsMean::GetResultsSoFar() const {
    vector<vector<double>> results(1);
    results[0].resize(1);
    results[0][0] = runningSum / PathsDone;

    return results;
}

StatisticsMC* StatisticsMean::clone() const {
    return new StatisticsMean(*this);
}

