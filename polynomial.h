#include <iostream>
using namespace std;

class Polynomial {
private:
    int order; // порядок многочлена
    int* coefficients; // набор коэффициентов

public:
    // Конструктор
    Polynomial(int order, int* coefficients);
    // Деструктор
    ~Polynomial();
    // Вычисление значения многочлена для данного параметра
    int evaluate(int x);
    // Вывод многочлена на экран
    char* c_str();
};

