#include <iostream>
using namespace std;

class Polynomial {
public:
    Polynomial();
    Polynomial(int order, int* coefficients);
    ~Polynomial();
    Polynomial(const Polynomial&);

    int evaluate(int x);
    Polynomial sum(const Polynomial& other) const;
    char* c_str();
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator++();
    Polynomial operator--();
    int operator()(int x);
    int& operator[](int index);
    Polynomial& operator=(const Polynomial& other);
    void setById(int id, int coefficients);
    int get(int id);
    static int count;
private:
    int order;
    int* coefficients;
    friend Polynomial operator+(const Polynomial& left, const Polynomial& right);
};
