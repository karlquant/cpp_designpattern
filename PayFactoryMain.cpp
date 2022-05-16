#include "PayOffFactory.h"
#include "PayOff3.h"
#include "PayOffConstructible.h"
//#include "PayOffBridge.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    double Strike;
    string payOffname;

    cout << "\n Enter PayOff\n";
    cin >> payOffname;

    cout << "\nEnter Strike\n";
    cin >> Strike;

    PayOff* payOffPtr = PayOffFactory::Instance().CreatePayOff(payOffname, Strike);

    if (payOffPtr != NULL) {
        double Spot;
        cout << "\nEnter Spot \n";
        cin >> Spot;
        double result = payOffPtr->operator()(Spot);
        cout << "\nPayOff is " << result;

        delete payOffPtr;
    }

    double tmp;
    cin >> tmp;



    return 0;
}