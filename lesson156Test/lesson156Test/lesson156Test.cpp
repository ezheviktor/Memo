#include <iostream>
#include <string>

class Fruit
{
	std::string m_name;
	std::string m_color;
public:
	Fruit(std::string name,std::string color ):m_name(name),m_color(color){}
	const std::string getColor() const { return m_color; }
	const std::string getName() const { return m_name; }
};

class Apple :public Fruit
{
	double m_fiber;
public:
	Apple(std::string name, std::string color, double fiber): Fruit(name,color),m_fiber(fiber){}
	friend std::ostream& operator<<(std::ostream& out, const Apple& myFruit) ;
};

class Banana :public Fruit
{
public:
	Banana(std::string name, std::string color):Fruit(name,color){}
	friend std::ostream& operator<<(std::ostream& out, const Banana& myFruit)
	{
		out <<"Banana ("<< myFruit.getName() << ", " << myFruit.getColor()<<")" ;
		return out;
	}
};

std::ostream& operator<<(std::ostream& out, const Apple& myFruit)
{
	out <<"Apple ( "<< myFruit.getName() << ", " << myFruit.getColor() << ", " << myFruit.m_fiber<<")";
	return out;
}

int main()
{
	const Apple a("Red delicious", "red", 7.3);
	std::cout << a;

	const Banana b("Cavendish", "yellow");
	std::cout << b;

	return 0;
}
