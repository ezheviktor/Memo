#include <iostream>
#include <string>
#include <array>
#include <vector>

class Ball
{
	std::string m_color;
	double m_radius;

public:
	/*Ball() { m_color = { "Red" }; m_radius = { 20.0 }; }
	Ball(std::string a) { m_color = a; m_radius = 20; }
	Ball(double a) { m_radius = a; m_color = "Red"; }
	Ball(std::string a, double b) { m_color = a; m_radius = b; }
	*/

	Ball(std::string a = { "Red" }, double b = 20.0)
	{
		m_color = a;
		m_radius = b;
	}
	Ball(double a)
	{
		m_color = { "Red" };
		m_radius = a;
	}
	
	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << std::endl;
	}
};


int main()
{
	Ball def;
	def.print();

	Ball black("black");
	black.print();

	Ball thirty(30.0);
	thirty.print();

	Ball blackThirty("black", 30.0);
	blackThirty.print();

	return 0;
}
