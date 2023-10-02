#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "polynomial.h"

using namespace std;

int main() {
    int order = 3;
    int coefficients[] = { 2, 1, -6, 3 };
    Polynomial polynomial(order, coefficients);

    cout << polynomial.c_str() << endl;

    int x = 2;
    int result = polynomial.evaluate(x);

    cout << "Polynomial value for x = " << x << ": " << result << endl;

    return 0;
}



