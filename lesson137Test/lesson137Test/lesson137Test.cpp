#include <iostream>
#include <map>
#include <string>
#include <vector>

struct StudentGrade
{
	std::string s_name;
	char s_grade;
};

class GradeMap
{
	std::vector<StudentGrade> m_map;
public:
	GradeMap(){}
	char& operator[](std::string name)
	{
		for (auto& element : m_map)
		{
			if (element.s_name == name)
				return element.s_grade;
		}

			StudentGrade temp{ name,' ' };
			m_map.push_back(temp);
			return m_map.back().s_grade;
		
	}
};
int main()
{
	GradeMap grades;
	grades["John"] = 'A';
	grades["Martin"] = 'B';
	std::cout << "John has a grade of " << grades["John"] << '\n';
	std::cout << "Martin has a grade of " << grades["Martin"] << '\n';

	return 0;
}
