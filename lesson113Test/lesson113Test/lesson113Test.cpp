#include <iostream>

class Numbers
{
public:
	int m_a;
	int m_b;

	void set(int value1, int value2)
	{
		m_a = value1;
		m_b = value2;
	}
	void print()
	{
		std::cout <<"Numbers("<< m_a << " ," << m_b <<")"<< std::endl;
	}
};

int main()
{
	Numbers n1;
	n1.set(3, 3); // инициализируем объект n1 значениями 3 и 3

	Numbers n2{ 4, 4 }; // инициализируем объект n2 значениями 4 и 4

	n1.print();
	n2.print();

	return 0;
}
