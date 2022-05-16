#include "PayOffFactory.h"
#include <iostream>
using namespace std;

void PayOffFactory::RegisterPayOff(string PayOffId, CreatePayOffFunction CreatorFunction) {
    theCreatorFunctions.insert(pair<string, CreatePayOffFunction>(PayOffId, CreatorFunction));
}

PayOff* PayOffFactory::CreatePayOff(string PayOffId, double Strike) {
    map<string, CreatePayOffFunction>::const_iterator i = theCreatorFunctions.find(PayOffId);

    if (i == theCreatorFunctions.end()) {
        cout << PayOffId << " is an unknown payoff type" << endl;
        return NULL;
    }

    return (i->second)(Strike);
}

PayOffFactory& PayOffFactory::Instance() {
    static PayOffFactory theFactory;
    return theFactory;
}