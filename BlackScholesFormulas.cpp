#include "BlackScholesFormulas.h"
#include "Normals.h"
#include <cmath>
using namespace std;

const double OneOverRootTwoPi = 0.398942280401433;

double BlackScholesCall(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
    double moneyness = Spot / Strike;
    double d1 = (log(moneyness) + (r-d+Vol*Vol)*Expiry) / (Vol * sqrt(Expiry));
    double d2 = d1 - Vol * sqrt(Expiry);

    return Spot * exp(-d * Expiry) * CumulativeNormal(d1) - Strike * exp(-r * Expiry) * CumulativeNormal(d2);
}


double BlackScholesPut(double Spot, double Strike, double r, double d, double Vol, double Expiry) {

    double moneyness = Spot / Strike;
    double d1 = (log(moneyness) + (r-d+Vol*Vol)*Expiry) / (Vol * sqrt(Expiry));
    double d2 = d1 - Vol * sqrt(Expiry);

    return Strike * exp(-r * Expiry) * CumulativeNormal(-d2) - Spot * exp(-d * Expiry) * CumulativeNormal(-d1);
}


double BlackScholesDigitalCall(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
    double moneyness = Spot / Strike;
    double d2 = (log(moneyness) + (r - d + 0.5 * Vol * Vol) * Expiry) / (Vol * sqrt(Expiry));

    return exp(-r * Expiry) * CumulativeNormal(d2);

}

double BlackScholesVega(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
    double moneyness = Spot / Strike;
    double d1 = (log(moneyness) + (r-d+Vol*Vol)*Expiry) / (Vol * sqrt(Expiry));

    return Spot * exp(-d * Expiry) * sqrt(Expiry) * OneOverRootTwoPi * exp(-0.5 * d1 * d1);
}

double BlackScholesCallDelta(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
    double moneyness = Spot / Strike;
    double d1 = (log(moneyness) + (r-d+Vol*Vol)*Expiry) / (Vol * sqrt(Expiry));
    return -exp(-d * Expiry) * CumulativeNormal(d1);

}

double BlackScholesCallTheta(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
    double moneyness = Spot / Strike;
    double d1 = (log(moneyness) + (r-d+Vol*Vol)*Expiry) / (Vol * sqrt(Expiry));
    double d2 = d1 - Vol * sqrt(Expiry);

    return -(Spot * Vol * exp(-d * Expiry)) / (2 * sqrt(Expiry)) * OneOverRootTwoPi * exp(-0.5 * d1 * d1) + d * Spot * exp(-d * Expiry) * CumulativeNormal(d1) - r * Strike * exp(-r * Expiry) * CumulativeNormal(d2);
}

double BlackScholesCallRho(double Spot, double Strike, double r, double d, double Vol, double Expiry) {
    double moneyness = Spot / Strike;
    double d2 = (log(moneyness) + (r - d + 0.5 * Vol * Vol) * Expiry) / (Vol * sqrt(Expiry));
    return Strike * Expiry * exp(-r * Expiry) * CumulativeNormal(d2);    
}
