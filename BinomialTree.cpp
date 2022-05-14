#include "BinomialTree.h"
#include <valarray>
#include <cmath>

using namespace std;

SimpleNominalTree::SimpleNominalTree(double Spot_, const Parameters& r_, const Parameters& d_, double Vol_, unsigned long Steps_, double Time_): Spot(Spot_), r(r_), d(d_), Volatility(Vol_), Steps(Steps_), Time(Time_) {
    TreeBuilt = false;
}

void SimpleNominalTree::BuildTree() {
    theTree.resize(Steps + 1);
    double initialLogSpot = log(Spot);
    for (unsigned long i=0; i <= Steps; i++) {
        theTree[i].resize(i+1);
        double thisTime = (i * Time) / Steps;
        double movedLogSpot = initialLogSpot + r.Integral(0.0, thisTime) - d.Integral(0.0, thisTime) - 0.5 * Volatility * Volatility * thisTime;

        double sd = Volatility * sqrt(Time / Steps);
        
        for (long j = -static_cast<long>(i), k=0; j<=static_cast<long>(i); j=j+2, k++){
            theTree[i][k].first = exp(movedLogSpot + j * sd);
        }


    }
    Discounts.resize(Steps);
    for (unsigned long l=0; l < Steps; l++) {
        Discounts[l] = exp(-r.Integral((l * Time) / Steps, (l + 1) * Time / Steps));
    }

    TreeBuilt = true;
}


double SimpleNominalTree::GetThePrice(const TreeProduct& theProduct) {
    if (!TreeBuilt) BuildTree();

    if (theProduct.GetFinalTime() != Time)
    {
        throw("mismatched product in SimpleNominalTree");
    }

    for (long j = -static_cast<long>(Steps), k=0; j <= static_cast<long>(Steps); j=j+2, k++) {
        theTree[Steps][k].second = theProduct.FinalPayOff(theTree[Steps][k].first);
    }

    for (unsigned long i = 1; i <= Steps; i++) {
        unsigned long index = Steps - i;
        double thisTime = index * Time / Steps;

        for (long j = -static_cast<long>(index), k=0; j <= static_cast<long>(index); j=j+2, k++) {
            theTree[index][k].second = theProduct.PreFinalValue(theProduct.FinalPayOff(theTree[index][k].first), thisTime, 0.5 * (theTree[index + 1][k].second + theTree[index + 1][k + 1].second) * Discounts[index] );
        } 
    }

    return theTree[0][0].second;
    
}