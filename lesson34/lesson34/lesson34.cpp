#include <iostream>

int enteredValue()
{
	std::cout << " Enter the value:";
	int x;
	std::cin >> x;
	return x;
}

bool logicValue(int x, int y = 2 or 3 or 7)
{
	return x == y;
}

int main()
{	
	int enteredValue();
	if (logicValue(x, y))
		std::cout << "The digit is prime" << std::endl;
	else
		std::cout << " The digit is not prime" << std::endl;
	return 0;

}

