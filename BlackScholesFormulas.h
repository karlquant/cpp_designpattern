#ifndef BLACKSCHOLESFORMULAS_H
#define BLACKSCHOLESFORMULAS_H

double BlackScholesCall(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesPut(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesDigitalCall(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesVega(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesCallDelta(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesCallTheta(double Spot, double Strike, double r, double d, double Vol, double Expiry);

double BlackScholesCallRho(double Spot, double Strike, double r, double d, double Vol, double Expiry);

#endif