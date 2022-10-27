#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

enum class Animal
{
	pig,
	chicken,
	goat,
	cat,
	dog,
	ostrich,
};

std::string getAnimalName(Animal a)
{
	using namespace std;

	switch (a)
	{
	case Animal::pig:
		return "Pig";
		break;
	case Animal::chicken:
		return "Chicken";
		break;
	case Animal::goat:
		return "Goat";
		break;
	case Animal::cat:
		return "Cat";
		break;
	case Animal::dog:
		return "Dog";
		break;
	case Animal::ostrich:
		return "Ostrich";
		break;
	default:
		return "Try again pls)";

	}
}
std::string printNumberOfLegs(Animal a)
{
	using namespace std;
	switch (a)
	{
	case Animal::pig:
		return "4";
		break;
	case Animal::chicken:
		return "2";
		break;
	case Animal::goat:
		return "4";
		break;
	case Animal::cat:
		return "4";
		break;
	case Animal::dog:
		return "4";
		break;
	case Animal::ostrich:
		return "2 if we dont count its neck))";
		break;
	default:
		return "Try again pls)";
	}
}

int main()
{
	int c;
	std::cin >> c;
	Animal a = static_cast<Animal>(c);
	Animal b = Animal::chicken;
	std::cout << "A " << getAnimalName(a) << " has " << printNumberOfLegs(a) << " legs\n";
	std::cout << "A " << getAnimalName(b) << " has " << printNumberOfLegs(b) << " legs\n";
	return 0;
}
