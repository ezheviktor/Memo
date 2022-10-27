#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
	char ch('a');
	while(ch<=122)
	{
		std::cout << ch << " "<< static_cast<int>(ch)<<"\n";
		++ch;
	}
}
