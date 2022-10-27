#include <iostream>

bool isEven(int x)
{
	
	if (x % 2 == 0)
		return true;
	else false;
}

int main()
{
	std::cout << " Enter value: ";
	int x;
	std::cin >> x;
	if (isEven(x))
		std::cout << "Your value can be divided by 2" << std::endl;
	else
		std::cout << "Wrong value" << std::endl;
	return 0;
}