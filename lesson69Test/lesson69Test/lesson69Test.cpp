#include <iostream>
#include <string>
#include <cmath>


/*int main()
{
	for (int n = 1; n <= 20; ++n)
	{
		if (n%2 == 0)
			std::cout << n << " ";
	}
}
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

int sumTo()
{
	std::cout << "enter the value: ";
	int value;
	std::cin >> value;

	
	int total=0;
	for (int n = 1; n <= value; ++n)
	{
		
		total +=n;

	}
	std::cout << "\n" << total;
	return total;
}

int main()
{
	sumTo();
	return 0;
}

