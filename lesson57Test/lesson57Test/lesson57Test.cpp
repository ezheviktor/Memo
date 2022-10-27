#include <iostream>
#include <string>

double a(int a, int b)
{
	return  a / b;
}

int main()
{
	std::cout << " Enter your full name please: "<<std::endl;
	std::string myName;
	std::getline(std::cin, myName);

	std::cout << " Enter your age please: " << std::endl;
	int age;
	std::cin >> age;

	std::cin.ignore(32767, '\n');

	std::cout << " You have lived " <<static_cast<double>(age)/myName.length() << " years for each letter in your name'\n'";
	return 0;
}
