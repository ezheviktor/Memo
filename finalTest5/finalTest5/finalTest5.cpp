/*#include <iostream>
#include "constants.h"
#include <cmath>
#include<math.h>


double enteredHeight()
{
	std::cout << "Enter the initial height of the tower in meters: ";
	double x;
	std::cin >> x;
	return x;
}

double finalHeight( double x)
{
	
	double t;
	for(t=0.0;;t+=0.1)
	{
		double passedWay = (constants::gravity * t * t )/ 2;
		double a = x - passedWay;
		if (passedWay < x )
			std::cout << "At " << t << " seconds the height is " << a << " meters " << std::endl;
		else if (passedWay >= x)
		{
			t = sqrt((2 * passedWay) / constants::gravity);
			std::cout << "At "<<t<<" seconds the ball will reach the ground\n";
			break;
		}
	}

	return 0;
}

int main()
{
	double x = enteredHeight();
	finalHeight(x);
	return 0;
}*/