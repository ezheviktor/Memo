#include <iostream>
//double temperature[365]={0.0}

namespace Animals
{
	enum Animals
	{
		chicken,
		lion,
		giraffe,
		elephant,
		duck,
		snake,
		amount,
	};
}

int main()
{
	int legs[Animals::amount] = { 2,4,4,4,2,0 };
	std::cout << legs[Animals::elephant]<<std::endl;
	return 0;
}
