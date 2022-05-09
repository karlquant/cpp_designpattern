#include "SimpleMC5.h"

#include "Random1.h"
#include <cmath>
using namespace std;

double SimpleMonteCarlo4(const VanillaOption& theOption, double Spot, double Vol, double r, unsigned long NumberOfPaths) {
    double Expiry = theOption.GetExpiry();
    double variance = Vol * Vol * Expiry;
    double rootvariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = Spot * exp(r * Expiry + itoCorrection);
    double thisSpot;
    double runningSum;

    for (unsigned long i =0; i < NumberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootvariance * thisGaussian);
        double thePayOff = theOption.OptionPayOff(thisSpot);
        runningSum += thePayOff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * Expiry);

    return mean;
}