#include <iostream>
using namespace std;

class Polynomial {
public:
	Polynomial(int order, int* coefficients);
	Polynomial(const Polynomial&);
	~Polynomial();
	int evaluate(int x);
	char* c_str();
	void setById(int id, int coefficients);
	int get(int id);
private:
	int order; // Порядок
	int* coefficients;

};
