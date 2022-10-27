#include <iostream>
#include <string>
#include <vector>

using namespace std;

//int factorial(int value)
//{
//	if (value == 1)
//		return 1;
//	else if(value>1)
//		return factorial(value - 1) * value;
//}
//
//int main()
//{
//	int value = 8;
//	cout << factorial(value);
//	return 0;
//]

void function(int a  )
{
	if (a == 1)
		std::cout<<"1";
	else if((a % 2) == 0)
	{
		 function(a / 2);
		 std::cout << "0";
	}
	else
	{
		function(a / 2);
		std::cout << "1";
	}
	
}

int main()
{
	cout << "Enter an integar: ";
	int a;
	cin >> a;

	if (a <= 0)
		a = -a;
	cout << "\n";
	function(a);
}
