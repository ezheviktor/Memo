#include <iostream>
#include "constants.h"

double enteredHeight()
{
	std::cout << "Enter the initial height of the tower in meters: ";
	double x;
	std::cin >> x;
	return x;
}

double finalHeight(int t, double x)
{

	double passedWay = constants::gravity * t*t/2;
	std::cout << "At" << t << "seconds the height is" << x - passedWay << "meters"<< std::endl;
	return 0;
}

int main()
{
	double x = enteredHeight();
	finalHeight(1,x);
	finalHeight(2,x);
	finalHeight(3,x);
	finalHeight(4,x);
	finalHeight(5,x);
	return 0;
}