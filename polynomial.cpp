#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "polynomial.h"
using namespace std;

    Polynomial::Polynomial(int order, int* coefficients) {
        this->order = order;
        this->coefficients = new int[order + 1];
        for (int i = 0; i <= order; i++) {
            this->coefficients[i] = coefficients[i];
        }
    }

    // Деструктор
    Polynomial::~Polynomial() {
        delete[] coefficients;
    }

    // Вычисление значения многочлена для данного параметра
    int Polynomial::evaluate(int x) {
        int result = 0;
        for (int i = 0; i <= order; i++) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    // Вывод многочлена на экран
    char* Polynomial::c_str() {
        char* str = new char[255];
        sprintf(str, "Polynomial: ");
        for (int i = order; i >= 0; --i) {
            if (i == 0) {
                sprintf(str, "%s%d ", str, coefficients[i]);
            }
            else if (i == 1) {
                sprintf(str, "%s%dx ", str, coefficients[i]);
            }
            else {
                sprintf(str, "%s%dx^%d ", str, coefficients[i], i);
            }
            if (coefficients[i] != 0 && coefficients[i - 1] > 0) {
                sprintf(str, "%s+", str);
            }
            else {
                sprintf(str, "%s", str);
            }


        }
        return str;
    }


