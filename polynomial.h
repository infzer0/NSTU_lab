#include <iostream>
using namespace std;

class Polynomial {
private:
    int order; // ������� ����������
    int* coefficients; // ����� �������������

public:
    // �����������
    Polynomial(int order, int* coefficients);
    // ����������
    ~Polynomial();
    // ���������� �������� ���������� ��� ������� ���������
    int evaluate(int x);
    // ����� ���������� �� �����
    char* c_str();
};

