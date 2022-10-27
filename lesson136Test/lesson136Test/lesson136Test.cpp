#include <iostream>
#include <algorithm>
#include <vector>

/*class Dollars
{
private:
    int m_dollars;

public:
    Dollars(int dollars) { m_dollars = dollars; }

    friend bool operator> (const Dollars& d1, const Dollars& d2);
    friend bool operator<= (const Dollars& d1, const Dollars& d2);

    friend bool operator< (const Dollars& d1, const Dollars& d2);
    friend bool operator>= (const Dollars& d1, const Dollars& d2);
};

bool operator> (const Dollars& d1, const Dollars& d2)
{
    return d1.m_dollars > d2.m_dollars;
}

bool operator>= (const Dollars& d1, const Dollars& d2)
{
    return d1.m_dollars >= d2.m_dollars;
}

bool operator< (const Dollars& d1, const Dollars& d2)
{
    return !(d1>=d2);
}

bool operator<= (const Dollars& d1, const Dollars& d2)
{
    return !(d1>d2);
}

int main()
{
    Dollars ten(10);
    Dollars seven(7);

    if (ten > seven)
        std::cout << "Ten dollars are greater than seven dollars.\n";
    if (ten >= seven)
        std::cout << "Ten dollars are greater than or equal to seven dollars.\n";
    if (ten < seven)
        std::cout << "Seven dollars are greater than ten dollars.\n";
    if (ten <= seven)
        std::cout << "Seven dollars are greater than or equal to ten dollars.\n";

    return 0;
}
*/

#include <string>

class Car
{
private:
    std::string m_company;
    std::string m_model;

public:
    Car(std::string company, std::string model)
        : m_company(company), m_model(model)
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
    friend std::ostream& operator<<(std::ostream& out, const Car& c);
    friend bool operator<(Car& c1, Car& c2);
};

std::ostream& operator<<(std::ostream& out, const Car& c)
{
    out <<"("<< c.m_company <<" , "<< c.m_model<<")";
    return out;
}

bool operator<(Car& c1, Car& c2)
{
    if (c1.m_company < c2.m_company)
        return true;
    else
        return false;
    if (c1.m_model < c2.m_model)
        return true;
    else
        return false;

    return false;
}

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_company == c2.m_company &&
        c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return !(c1 == c2);
}

int main()
{
    std::vector<Car> v;
    v.push_back(Car("Ford", "Mustang"));
    v.push_back(Car("Renault", "Logan"));
    v.push_back(Car("Ford", "Ranger"));
    v.push_back(Car("Renault", "Duster"));

    std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для класса Car

    for (auto& car : v)
        std::cout << car << '\n'; // требуется перегрузка оператора << для класса Car

    return 0;
}
