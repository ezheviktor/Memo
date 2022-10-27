#include <iostream>
class Fraction
{
	int m_numerator;
	int m_denominator;
public:
    Fraction(int numerator = 0, int denominator = 0) :m_numerator(numerator), m_denominator(denominator) { reduce(); }
	void print(){ std::cout << m_numerator << "/" << m_denominator << std::endl;}
    int nod(int a, int b) {
        return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
    }
    void reduce()
    {
        int nod = Fraction::nod(m_numerator, m_denominator);
        m_numerator /= nod;
        m_denominator /= nod;
    }

    friend Fraction operator*(Fraction& v, int value);
    friend Fraction operator*(int value, Fraction& v);
    friend Fraction operator*(Fraction v, Fraction w);
};

Fraction operator*(Fraction& v, int value)
{
    return Fraction(v.m_numerator * value, v.m_denominator);
}
Fraction operator*(int value, Fraction& v)
{
    return v * value;
}
Fraction operator*(Fraction v, Fraction w)
{
    return Fraction(v.m_numerator * w.m_numerator, v.m_denominator*w.m_denominator);
}


int main()
{
    Fraction f1(3, 4);
    f1.print();

    Fraction f2(2, 7);
    f2.print();

    Fraction f3 = f1 * f2;
    f3.print();

    Fraction f4 = f1 * 3;
    f4.print();

    Fraction f5 = 3 * f2;
    f5.print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();

    return 0;
}