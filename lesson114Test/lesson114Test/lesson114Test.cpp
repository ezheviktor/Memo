#include <iostream>
#include <array>
#include <cassert>

/*
class Numbers
{
	double m_a;
	double m_b;
	double m_c;

public:
	void setValues(double a, double b, double c)
	{
		m_a = a;
		m_b = b;
		m_c = c;
	}
	void print()
	{
		std::cout<< "<" << m_a << "," << m_b << "," << m_c << ">" << std::endl;
	}
	bool isEqual(const Numbers &b)
	{
		return (m_a == b.m_a && m_b == b.m_b && m_c == b.m_c);
	}
};

int main()
{
	Numbers point1;
	point1.setValues(3.0, 4.0, 5.0);

	Numbers point2;
	point2.setValues(3.0, 4.0, 5.0);

	if (point1.isEqual(point2))
		std::cout << "point1 and point2 are equal\n";
	else
		std::cout << "point1 and point2 are not equal\n";

	Numbers point3;
	point3.setValues(7.0, 8.0, 9.0);

	if (point1.isEqual(point3))
		std::cout << "point1 and point3 are equal\n";
	else
		std::cout << "point1 and point3 are not equal\n";

	return 0;
}
*/

class Stack
{
public:
	int m_array[10];
	int m_next;
	void reset()
	{
		for (auto element : m_array)
		{
			element = 0;
		}
		m_next = 0;
	}
	bool push(int a)
	{
		if (m_next == 10)
		{
			return false;
		}
		else
		{
			m_array[m_next] = a;
			++m_next;
			return true;
		}
	}
	int pop()
	{
		assert( m_next > 0);
		return m_array[m_next--];
	}
	void print()
	{
		std::cout << "(";
		for (int i = 0; i < m_next; ++i)
		{
			std::cout << m_array[i]<<" , ";
		}
		std::cout << ")\n";
	}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
