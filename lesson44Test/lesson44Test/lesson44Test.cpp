#include <iostream>
#include <cmath>

int function(int x)
{
	if (x >= 128)
		std::cout << "1";
	else
		std::cout << "0";
	if (128 - x >= 64)
		std::cout << "1";
	else
		std::cout << "0";
	if (64-(128-x)>=32)
		std::cout << "1";
	else 
		std::cout << "0";
	if (32-(64-(128-x))>=16)
		std::cout << "1";
	else 
		std::cout << "0";
	if (16-(32 - (64 - (128 - x)))>=8)
		std::cout << "1";
	else
		std::cout << "0";
	if (8- (16 - (32 - (64 - (128 - x))))>=4)
		std::cout << "1";
	else 
		std::cout << "0";
	if (4-(8 - (16 - (32 - (64 - (128 - x)))))>2)
		std::cout << "1";
	else
		std::cout << "0";
	if (2-(4 - (8 - (16 - (32 - (64 - (128 - x))))))>=1)
		std::cout << "1";
	else
		std::cout << "0";
	return 0;

}

int main()
{
	std::cout << "Enter the number from 0 to 255: " << std::endl;
	int x;
	std::cin >> x;
	if (x >= 0 && x <= 255)
		std::cout << "your number is coorrect, it is"<< function(x) <<std::endl ;
	else
		std::cout << "enter another number";
	return 0;
}

