#ifndef PAYOFFFACTORY_H
#define PAYOFFFACTORY_H

#include "PayOff3.h"
#include <map>
#include <string>
using namespace std;

class PayOffFactory {
    public: 
        typedef PayOff* (*CreatePayOffFunction) (double );

        static PayOffFactory& Instance();
        void RegisterPayOff(string, CreatePayOffFunction);
        PayOff* CreatePayOff(string payOffId, double Strike);
        ~PayOffFactory() {};
    private:
        map<string, CreatePayOffFunction> theCreatorFunctions;

        PayOffFactory(){};
        PayOffFactory(const PayOffFactory&) {};
        PayOffFactory& operator=(const PayOffFactory&) {return *this;};
};


#endif