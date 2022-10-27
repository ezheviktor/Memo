#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

void calculate(int a,int b,char sign)
{
	using namespace std;

	switch (sign)
	{
	case '+':
		cout << "The result of" << a << sign << b << " = " << a + b << endl;
		break;
	case '-':
		cout << "The result of" << a << sign << b << " = " << a - b << endl;
		break;
	case '*':
		cout << "The result of" << a << sign << b << " = " << a * b << endl;
		break;
	case '/':
		cout << "The result of" << a << sign << b << " = " << a / b << endl;
		break;
	case '%':
		cout << "The result of" << a << sign << b << " = " << a % b << endl;
		break;
	default:
		cout << "Tyi typoi)))\n";

	}

}

int main()
{
	using namespace std;
	cout << "Enter the first value: ";
	int a;
	cin >> a;

	cout << "\nEnter the second value: ";
	int b;
	cin >> b;

	cout << "Enter the chosen operation(+,-,/,*,%): ";
	char sign;
	cin >> sign;
	calculate(a, b, sign);
}