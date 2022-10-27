#include <iostream>



int main()
{
	std::cout << "Enter a double value:" << std::endl;
	double value1;
	std::cin >> value1;
	

	std::cout << "Enter a second double value:" << std::endl;
	double value2;
	std::cin >> value2;
	

	std::cout << "Enter one of the following : +, -, *, or / :";
	int sign;
	std::cin >> sign;
	
	if (sign=='+')
		std::cout << value1 << '+' << value2 << '=' << value1 + value2;
	else if (sign=='-')
		std::cout << value1 << '-' << value2 << '=' << value1 - value2;
	else if (sign=='*')
		std::cout << value1 << '*' << value2 << '=' << value1 * value2;
	else if (sign=='/')
		std::cout << value1 << '/' << value2 << '=' << value1 / value2;

	return 0;
}