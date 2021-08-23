#include <iostream>
using namespace std;

class A {
public:
	void Say()& { cout << "L-value metod" << endl; } //Вызывается у созданного объекта
	void Say()&& { cout << "R-value metod" << endl; } //Вызывается у анонимного объекта
	void Say() const& { cout << "const L-value metod" << endl; } //Вызывается у созданного константного объекта
	void Say() const&& { cout << "const R-value metod" << endl; } //Вызывается у анонимного константного объекта

	//int& a - Ссылка L-value , int&&b - Ссылка R-value
	void sum(int& a, int& b)& { cout << "L-value metod. Sum l-value + l-value = " << a + b << endl; } //Вызывается у созданного объекта
	void sum(int&& a, int&& b)&& { cout << "R-value metod. Sum r-value + r-value = " << a + b << endl; } //Вызывается у анонимного объекта
	void sum(int& a, int& b) const& { cout << "const L-value metod. Sum l-value + l-value = " << a + b << endl; } //Вызывается у созданного константного объекта
	void sum(int&& a, int&& b) const&& { cout << "const R-value metod. Sum r-value + r-value = " << a + b << endl; } //Вызывается у анонимного константного объекта
	void sum(int& a, int&& b)& { cout << "L-value metod. Sum l-value + r-value = " << a + b << endl; } //Вызывается у созданного объекта
	void sum(int& a, int&& b)&& { cout << "R-value metod. Sum l-value + r-value = " << a + b << endl; } //Вызывается у анонимного объекта
	void sum(int& a, int&& b) const& { cout << "const L-value metod. Sum l-value + r-value = " << a + b << endl; } //Вызывается у созданного константного объекта
	void sum(int& a, int&& b) const&& { cout << "const R-value metod. Sum l-value + r-value = " << a + b << endl; } //Вызывается у анонимного константного объекта
};


int main()
{
	A a; //Объект L-value
	a.Say(); //Объект L-value
	A().Say(); //Анонимный объект R-value
	const A b; //Константный объект L-value
	b.Say(); //Константный объект L-value
	const A().Say(); //Константный анонимный объект R-value
	int value{ 10 }; // Значение L-value
	a.sum(value, value); //Объект L-value
	A().sum(7, 9);//Анонимный объект R-value
	b.sum(value, value); //Константный объект L-value
	const A().sum(20, 89); //Константный анонимный объект R-value
	a.sum(value, 26); //Объект L-value
	A().sum(value, 73);//Анонимный объект R-value
	b.sum(value, 46); //Константный объект L-value
	const A().sum(value, 58);//Константный анонимный объект R-value

}