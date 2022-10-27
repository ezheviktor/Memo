#include <iostream>
#include <cmath>


int main()
{
	setlocale(LC_ALL, "rus");

	//создаются переменные х и у
	std::cout << " Введите число: ";
	int x;
	std::cin >> x;

	std::cout << " Введите большее число: ";
	int y;
	std::cin >> y;

	if (x > y)
	{
		std::cout << " Меняем значения местами)" << std::endl;
		int a = x;//создаются переменные а и б во внутреннем блоке if
		int b = y;
		std::cout << " Меньшее число: " << b << std::endl;
		std::cout << " Большее число: " << a << std::endl;
		//уничтожаются переменные а и б во внутренем блоке if
	}

	else
	{
		int a = x;//создаются переменные а и б во внутреннем блоке else
		int b = y;
		std::cout << " Меньшее число: " << a << std::endl;
		std::cout << " Большее число: " << b << std::endl;
		// уничтожаются переменные а и б во внутренем блоке if
	}

	return 0;
	// уничтожаются переменные х и у
}
