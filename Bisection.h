#include <cmath>

template <class T>
double Bisection(double Target, double Low, double High, double Tolerance, T theFunction) {
    double x = 0.5 * (Low + High);
    double y = theFunction(x);

    do {

        if (y > Target) 
        {
            High = x;
        } 
        if (y < Target)
        {
            Low = x;
        }
        x = 0.5 * (Low + High);
        y = theFunction(x);
        
    } while (fabs(y - Target) > Tolerance);

    return x;
}