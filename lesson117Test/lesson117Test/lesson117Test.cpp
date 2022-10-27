#include <iostream>
#include <cstdint>
#include <string>

using  num =std::uint8_t;
class RGBA
{
	num m_red;
	num m_green;
	num m_blue;
	num m_alpha;

public:
	RGBA(num a=0,num b=0,num c=0,num d=255)
		:m_red(a),
		m_green(b),
		m_blue(c),
		m_alpha(d)
	{}
	void print()
	{
		std::cout <<static_cast<int> (m_red) << " " << static_cast<int>(m_green) << " " <<  static_cast<int> (m_blue) << " " <<  static_cast<int>( m_alpha) << " \n";
	}

};


int main()
{
	RGBA color(0, 135, 135);
	color.print();

	return 0;
}
