#include <iostream>
#include <string>
#include <cmath>

static struct Fructional
{
	int numenator;
	int denominator;
};

static double multiply(Fructional a, Fructional b)
{
	using namespace std;
	double c{ ((static_cast<double>(a.numenator) * b.numenator) / (a.denominator * b.denominator)) };
	return c;
}

int main()
{
	using namespace std;
	cout << "Enter the numenator and denominator of the first number: ";
	int num1;
	cin >> num1; '\n';
	int denom1;
	cin >> denom1; '\n';

	cout << "Enter the numenator and denominator of the second number: ";
	int num2;
	cin >> num2; '\n';
	int denom2;
	cin >> denom2; '\n';

	Fructional a{num1,denom1};
	Fructional b{num2,denom2};

	cout << "The result of the operation is " << multiply(a, b) << endl;
	return 0;
}