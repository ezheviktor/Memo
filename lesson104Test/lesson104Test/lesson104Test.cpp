#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;
typedef int (*arithmeticFcn)(int, int);

struct arithmeticStruct
{
	char sign;
	arithmeticFcn funct;
};



int getValue()
{
	start:
	cout << "Enter the value: \n";
	int a;
	cin >> a ;
	if (std::cin.fail()) // если предыдущее извлечение не выполнилось или произошло переполнение,
	{
		std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
		std::cin.ignore(32767, '\n');
		goto start;
	}
	return a;
}

char getSign()
{
	start2:
	cout << "Enter the sign of the operation(+,-,*,/): \n";
	char operation;
	cin >> operation;
	if (operation!='+'&&operation!='-'&&operation!='*'&&operation!='/') // если предыдущее извлечение не выполнилось или произошло переполнение,
		goto start2;    // и удаляем значения предыдущего ввода из входного буфера
	return operation;
}

int add(int a, int b)
{
	return a + b;
}
int substract(int a, int b)
{
	return a - b;
}
int multiply(int a, int b)
{
	return a * b;
}
int divide(int a, int b)
{
	return a / b;
}

static arithmeticStruct array[4] = { {'+', add},{'-',substract},{'*',multiply},{'/',divide} };

arithmeticFcn getArithmeticFcn(char sign)
{
	/*if (sign == '+')
		return add;
	else if (sign == '-')
		return substract;
	else if (sign == '*')
		return multiply;
	else if (sign == '/')
		return divide;*/

	for (auto element:array)
	{
		return array.funct;
	}
}

int main()
{
	
	int a = getValue();
	int b = getValue();
	char sign = getSign();
	return 0;
}