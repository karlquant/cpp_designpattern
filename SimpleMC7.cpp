#include "SimpleMC7.h"
#include "Random1.h"
#include <cmath>

using namespace std;

void SimpleMonteCarlo7(const VanillaOption& theOption, double Spot, const Parameters& Vol, const Parameters& r, unsigned long NumberOfPaths, StatisticsMC& gatherer) {
    double Expiry = theOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootvariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;
    double discount_factor = exp(-r.Integral(0, Expiry));

    double movedSpot = Spot * exp(r.Integral(0, Expiry) + itoCorrection);
    double thisSpot;
    for (unsigned long i = 0; i < NumberOfPaths; i++ ){
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootvariance * thisGaussian);
        double thePayOff = theOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thePayOff * discount_factor);
    }

    return;
}