#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <string_view>
#include <utility>


/*
struct Student
{
	string name;
	int grade;
};

std::array<Student, 8> arr{
  { { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 },
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 } }
};

int main()
{
    auto largest
    { 
        std::max_element(arr.begin(), arr.end(), [](Student a, Student b) {return (b.grade > a.grade); })
    };

    cout << largest->name << " is the best student\n";
    return 0;
}
*/

struct Season
{
    std::string name{};
    double averageTemperature{};
};

int main()
{
    std::array<Season, 4> seasons{
      { { "Spring", 285.0 },
        { "Summer", 296.0 },
        { "Fall", 288.0 },
        { "Winter", 263.0 } }
    };

    std::sort(seasons.begin, seasons.end, [](Season a, Season b) {
        return (a.averageTemperature < b.averageTemperature); });

    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }

    return 0;
}