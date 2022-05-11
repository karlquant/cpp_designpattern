#include "SimpleMC8.h"
#include <cmath>

using namespace std;

void SimpleMonteCarlo8(const VanillaOption& theOption, double Spot, const Parameters& Vol, const Parameters& r, unsigned long NumberOfPaths, StatisticsMC& gatherer, RandomBase& generator) {
    double Expiry = theOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootvariance = sqrt(variance);
    double itoCorrection = -0.5*variance;

    double movedSpot = Spot * exp(r.Integral(0, Expiry) + itoCorrection);
    double thisSpot;
    double thisDiscounting = exp(-r.Integral(0, Expiry));

    valarray<double> variatearray(1);

    for (unsigned long i=0; i < NumberOfPaths; i++) {
        generator.GetGaussians(variatearray);
        double thisGaussian = variatearray[0];
        thisSpot = movedSpot * exp(rootvariance * thisGaussian);
        double thisPayOff = theOption.OptionPayOff(thisSpot);
        
        gatherer.DumpOneResult(thisPayOff * thisDiscounting);

    }

    return;
}