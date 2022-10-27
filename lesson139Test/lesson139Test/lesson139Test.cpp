#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <string_view>
#include <vector>
using namespace std;
class String
{
	std::string myString;
public:
	String(std::string a):myString(a){}
	string operator() (int startIndex,int amount)
	{
		std::string chosen;
		for (int i = 0; i < amount; ++i)
		{
			chosen.push_back(myString[startIndex++]);
		}
		return chosen;
	}
};

int main()
{
	String string("Hello, world!");
	std::cout << string(7, 6)<<std::endl; // начинаем с 7 символа (индекса) и возвращаем следующие 6 символов

	return 0;
}
