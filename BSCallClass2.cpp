#include "BlackScholesFormulas.h"
#include "BSCallClass2.h"


BSCallTwo::BSCallTwo(double r_, double d_, double T_, double Spot_, double Strike_): r(r_), d(d_), T(T_), Spot(Spot_), Strike(Strike_) {

}

double BSCallTwo::Price(double Vol) const {
    return BlackScholesCall(Spot, Strike, r, d, Vol, T);
}

double BSCallTwo::Vega(double Vol) const {
    return BlackScholesVega(Spot, Strike, r, d, Vol, T);
}