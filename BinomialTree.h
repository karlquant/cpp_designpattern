#ifndef BINOMIALTREE_H
#define BINOMIALTREE_H

#include "TreeProducts.h"
#include <vector>
#include "Parameters.h"
#include <valarray>

using namespace std;

class SimpleNominalTree {
    public:
        SimpleNominalTree(double Spot_, const Parameters& r_, const Parameters& d_, double Vol_, unsigned long Steps_, double Time_);
        double GetThePrice(const TreeProduct& theProduct);
    protected:
        void BuildTree();

    private:
        double Spot;
        Parameters r;
        Parameters d;
        double Volatility;
        unsigned long Steps;
        double Time;
        bool TreeBuilt;

        vector<vector<pair<double, double>>> theTree;
        valarray<double> Discounts;


};

#endif