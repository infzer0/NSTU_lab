#define _CRT_SECURE_NO_WARNINGS
#include "polynomial.h"

int Polynomial::count = 0;

//Конструктор 
Polynomial::Polynomial() {
    order = 3;
    coefficients = new int[order + 1];
    coefficients[0] = 0.0;
    count++;
}

//Конструктор копирования
Polynomial::Polynomial(const Polynomial& f) {
    order = f.order;
    coefficients = new int[order + 1];
    for (int i = 0; i <= order; ++i) {
        coefficients[i] = f.coefficients[i];
    }
    count++;
}
//Конструктор 
Polynomial::Polynomial(int order, int* coefficients) {
    if (order < 0  || coefficients == nullptr) {
        throw invalid_argument("Некорректные данные");
    }
    this->order = order;
    this->coefficients = new int[order + 1];
    for (int i = 0; i <= order; i++) {
        this->coefficients[i] = coefficients[i];
    }
    count++;
}
// Деструктор
Polynomial::~Polynomial() {
    delete[] coefficients;
    count--;
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
    sprintf(str, "");
    for (int i = order; i >= 0; --i) {
        if (coefficients[i] == 0) {
            continue;
        }
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
        throw invalid_argument("Некорректный индекс");
    }
    coefficients[index] = value;
}

// Получение коэффициента по заданному индексу
int Polynomial::get(int index) {
    if (index < 0 || index > order) {
        throw invalid_argument("Некорректный индекс");
    }
    return coefficients[index];
}

Polynomial Polynomial::sum(const Polynomial& other) const {
    int maxOrder = max(order, other.order);
    int* newCoefficients = new int[maxOrder + 1];
    for (int i = 0; i <= maxOrder; i++) {
        int thisCoefficient = (i <= order) ? coefficients[i] : 0;
        int otherCoefficient = (i <= other.order) ? other.coefficients[i] : 0;
        newCoefficients[i] = thisCoefficient + otherCoefficient;
    }
    Polynomial sum(maxOrder, newCoefficients);
    return sum;
}

// Перегрузка оператора вычитания
Polynomial Polynomial::operator-(const Polynomial& other) const {
    int maxOrder = max(order, other.order);
    int* newCoefficients = new int[maxOrder + 1];
    for (int i = 0; i <= maxOrder; i++) {
        int thisCoefficient = (i <= order) ? coefficients[i] : 0;
        int otherCoefficient = (i <= other.order) ? other.coefficients[i] : 0;
        newCoefficients[i] = thisCoefficient - otherCoefficient;
    }
    Polynomial difference(maxOrder, newCoefficients);
    return difference;
}

Polynomial Polynomial::operator++() {
    int* newCoefficients = new int[order + 2];
    newCoefficients[0] = 0;
    for (int i = 1; i <= order + 1; i++) {
        newCoefficients[i] = coefficients[i - 1];
    }
    Polynomial incremented(order + 1, newCoefficients);
    delete[] newCoefficients;
    return incremented;
}

Polynomial Polynomial::operator--() {
    if (order == 0) {
        return *this;
    }
    int* newCoefficients = new int[order];
    for (int i = 0; i < order; i++) {
        newCoefficients[i] = coefficients[i + 1];
    }
    Polynomial decremented(order - 1, newCoefficients);
    delete[] newCoefficients;
    return decremented;
}

int Polynomial::operator()(int x) {
    return evaluate(x);
}

int& Polynomial::operator[](int index) {
    if (index < 0 || index > order) {
        throw out_of_range("Invalid index");
    }
    return coefficients[index];
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this == &other) {
        return *this;
    }
    delete[] coefficients;
    order = other.order;
    coefficients = new int[order + 1];
    for (int i = 0; i <= order; i++) {
        coefficients[i] = other.coefficients[i];
    }
    return *this;
}
Polynomial operator+(const Polynomial& left, const Polynomial& right) {
    Polynomial result = left;
    return result.sum(right);
}
