#define _CRT_SECURE_NO_WARNINGS
#include "polynomial.h"
using namespace std;

int main() {
    Polynomial p1;
    p1.setById(0, 3);
    p1.setById(1, 4);
    p1.setById(2, 2);
    p1.setById(3, 9);

    Polynomial p2;
    p2.setById(0, 10);
    p2.setById(1, 7);
    p2.setById(2, 2);
    p2.setById(3, 6);
    
    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial incr = ++p1;
    Polynomial decr = --p2;
    Polynomial assign = p1 = p2;

    int id = p1[2];
    int value = p1(9);

    cout << "Sum: " << sum.c_str() << endl;
    cout << "Difference: " << diff.c_str() << endl;
    cout << "Incremented: " << incr.c_str() << endl;
    cout << "Decremented: " << decr.c_str() << endl;
    cout << "Value: " << value << endl;
    cout << "ID: " << id << endl;
    cout << "Assignment: " << assign.c_str() << endl;

    return 0;
}


