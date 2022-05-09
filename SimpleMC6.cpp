#include "SimpleMC6.h"
#include "Random1.h"
#include <cmath>

using namespace std;

double SimpleMonteCarlo6(const VanillaOption& theOption, double Spot, const Parameters& Vol, const Parameters& r, unsigned long NumberOfPaths) {
    double Expiry = theOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = Spot * exp(r.Integral(0, Expiry) + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for (unsigned long i=0; i < NumberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayOff = theOption.OptionPayOff(thisSpot);
        runningSum += thisPayOff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r.Integral(0, Expiry));

    return mean;
}