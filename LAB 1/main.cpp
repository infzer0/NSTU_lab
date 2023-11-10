#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "polynomial.h"

using namespace std;

int main() {
    int coefficients[] = { 1, 7, 12, 43 };
    Polynomial polynomial(3, coefficients);
    cout << polynomial.c_str() << endl;

    int x = 7;
    int result = polynomial.evaluate(x);
    cout << "Polynomial value for x = " << x << ": " << result << endl;

    polynomial.setById(2, 6);
    cout << polynomial.c_str() << endl;

    int coefficient = polynomial.get(2);
    cout << "Coefficient at index 2: " << coefficient << endl;

    return 0;
}
