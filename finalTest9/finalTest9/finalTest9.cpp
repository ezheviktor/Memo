#include <iostream>
#include <cassert>
#include <iomanip>
/*
class Average
{
	int32_t numerator;
	int8_t denominator;
public:
	Average(int32_t n = 0,int8_t d=0):numerator(n),denominator(d) {}
	Average(const Average& a): numerator(a.numerator),denominator(a.denominator){}
	Average operator+=(int32_t v)
	{
		numerator += v;
		++denominator;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, const Average& v);
};

std::ostream& operator<<(std::ostream& out, const Average& v)
{
	assert(v.denominator != 0);
	out << v.numerator / v.denominator;
	return out;
}

int main()
{
	Average avg;

	avg += 5;
	std::cout << avg << '\n'; // 5 / 1 = 5

	avg += 9;
	std::cout << avg << '\n'; // (5 + 9) / 2 = 7

	avg += 19;
	std::cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11

	avg += -9;
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6

	(avg += 7) += 11; // выполнение цепочки операций
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
} */


//class IntArray
//{
//private:
//	int m_length = 0;
//	int* m_array = nullptr;
//
//public:
//	IntArray(int length) :
//		m_length(length)
//	{
//		assert(length > 0 && "IntArray length should be a positive integer");
//
//		m_array = new int[m_length] { 0 };
//	}
//
//	// Конструктор копирования, который выполняет глубокое копирование
//	IntArray(const IntArray& array) :
//		m_length(array.m_length)
//	{
//		// Выделяем новый массив
//		m_array = new int[m_length];
//
//		// Копируем элементы из исходного массива в наш, только что выделенный, массив
//		for (int count = 0; count < array.m_length; ++count)
//			m_array[count] = array.m_array[count];
//	}
//
//	~IntArray()
//	{
//		delete[] m_array;
//	}
//
//	// Функция перегрузки оператора <<
//	friend std::ostream& operator<<(std::ostream& out, const IntArray& array)
//	{
//		for (int count = 0; count < array.m_length; ++count)
//		{
//			out << array.m_array[count] << ' ';
//		}
//		return out;
//	}
//
//	int& operator[] (const int index)
//	{
//		assert(index >= 0);
//		assert(index < m_length);
//		return m_array[index];
//	}
//
//	// Перегрузка оператора присваивания с выполнением глубокого копирования
//	IntArray& operator= (const IntArray& array)
//	{
//		// Проверка на самоприсваивание
//		if (this == &array)
//			return *this;
//
//		// Если массив уже существует, то удаляем его, дабы не произошла утечка памяти
//		delete[] m_array;
//
//		m_length = array.m_length;
//
//		// Выделяем новый массив
//		m_array = new int[m_length];
//
//		// Копируем элементы из исходного массива в наш, только что выделенный, массив
//		for (int count = 0; count < array.m_length; ++count)
//			m_array[count] = array.m_array[count];
//
//		return *this;
//	}
//
//};
//
//IntArray fillArray()
//{
//	IntArray a(6);
//	a[0] = 6;
//	a[1] = 7;
//	a[2] = 3;
//	a[3] = 4;
//	a[4] = 5;
//	a[5] = 8;
//
//	return a;
//}
//
//int main()
//{
//	IntArray a = fillArray();
//
//	// Если у вас здесь получается какая-то чепуха, то, скорее всего, вы забыли выполнить глубокое копирование в вашем конструкторе копирования
//	std::cout << a << '\n';
//
//	IntArray b(1);
//	a = a;
//	b = a;
//
//	// Если у вас здесь получается какая-то чепуха, то, скорее всего, вы забыли выполнить глубокое копирование в своей функции перегрузки оператора присваивания,
//	// либо забыли о проверке на самоприсваивание
//	std::cout << b << '\n';
//
//	return 0;
//}

//class FixedPoint
//{
//	int16_t m_numerator;
//	int8_t m_denominator;
//public:
//	FixedPoint(int16_t numerator, int8_t denominator) :m_numerator(numerator), m_denominator(denominator) {}
//	friend std::ostream& operator<<(std::ostream& out, const FixedPoint& v)
//	{
//		if (v.m_numerator < 0 || v.m_denominator < 0)
//		{
//			if (v.m_numerator < 0)
//				static_cast<unsigned>(v.m_numerator);
//			if (v.m_denominator < 0)
//				static_cast<unsigned>(v.m_denominator);
//
//			double a=static_cast<double>(v.m_numerator);
//			double b = static_cast<double>(v.m_denominator)/100;
//			double c = a + b;
//
//			out <<std::fixed<<std::setprecision(2) << -c;
//		}
//		else
//		{
//			double a = static_cast<double>(v.m_numerator);
//			double b = static_cast<double>(v.m_denominator) / 100;
//			double c = a + b;
//
//			out << std::fixed << std::setprecision(2) << c;
//		}
//		return out;
//	}
//};
//
//
//int main()
//{
//	FixedPoint a(37, 58);
//	std::cout << a << '\n';
//
//	FixedPoint b(-3, 9);
//	std::cout << b << '\n';
//
//	FixedPoint c(4, -7);
//	std::cout << c << '\n';
//
//	FixedPoint d(-5, -7);
//	std::cout << d << '\n';
//
//	FixedPoint e(0, -3);
//	std::cout << e << '\n';
//
//
//	return 0;
//}

#include <cstdint> // для целочисленных значений фиксированного размера

class FixedPoint
{
private:
	std::int16_t m_base; // это целая часть значения
	std::int8_t m_decimal; // это дробная часть значения

public:
	FixedPoint(std::int16_t base = 0, std::int8_t decimal = 0)
		: m_base(base), m_decimal(decimal)
	{
		// Здесь нам нужно обработать случай, когда дробная часть > 99 или < -99,
		// но это вы должны будете сделать самостоятельно

		// Если целая или дробная части отрицательные
		if (m_base < 0.0 || m_decimal < 0.0)
		{
			// Проверяем целую часть
			if (m_base > 0.0)
				m_base = -m_base;
			// Проверяем дробную часть
			if (m_decimal > 0.0)
				m_decimal = -m_decimal;
		}
	}

	operator double() const
	{
		return m_base + static_cast<double>(m_decimal) / 100;
	}

	friend std::ostream& operator<<(std::ostream& out, const FixedPoint& fp)
	{
		out << static_cast<double>(fp);
		return out;
	}
};

void SomeTest()
{
	std::cout << std::boolalpha;
	std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << '\n'; // оба значения положительные, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << '\n'; // оба значения положительные, переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << '\n'; // оба значения отрицательные, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << '\n'; // оба значения отрицательные, переполнение
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << '\n'; // второе значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << '\n'; // второе значение отрицательное, возможно переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << '\n'; // первое отрицательное, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << '\n'; // первое отрицательное, возможно переполнение
}

int main()
{
	SomeTest();

	FixedPoint a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // введите 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}