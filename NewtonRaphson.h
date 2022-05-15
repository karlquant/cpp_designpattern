#include <cmath>

template<class T, double (T::*Value) (double) const, double (T::*Derivative) (double) const>
double NewtonRaphson(double Target, double Start, double Tolerance, const T& theFunction) {
    double y = (theFunction.*Value)(Start);

    double x = Start;
    while ( fabs(y - Target) > Tolerance)
    {
        x += (Target - y) / (theFunction.*Derivative)(x);
        y = (theFunction.*Value)(x);
    }

    return x;
    
}