#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "polynomial.h"
using namespace std;

//Конструктор
Polynomial::Polynomial(int order, int* coefficients) {
    if (order < 0 || coefficients == nullptr || coefficients[order] == 0) {
        throw std::invalid_argument("Некорректные данные");
    }
    this->order = order;
    this->coefficients = new int[order + 1];
    for (int i = 0; i <= order; i++) {
        this->coefficients[i] = coefficients[i];
    }
}

//Конструктор копирования
Polynomial::Polynomial(const Polynomial& f) {
    order = f.order;
    coefficients = new int[order + 1];
    for (int i = 0; i <= order; ++i) {
        coefficients[i] = f.coefficients[i];
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

// Вывод на экран
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

// Установка коэффициента по заданному индексу
void Polynomial::setById(int index, int value) {
    if (index < 0 || index > order) {
        throw std::invalid_argument("Некорректный индекс");
    }
    coefficients[index] = value;
}

// Получение коэффициента по заданному индексу
int Polynomial::get(int index) {
    if (index < 0 || index > order) {
        throw std::invalid_argument("Некорректный индекс");
    }
    return coefficients[index];
}
