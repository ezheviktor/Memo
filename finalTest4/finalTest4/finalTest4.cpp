#include <iostream>
#include <cmath>
#include <string>

enum class MONSTER
{
	OGRE,
	GOBLIN,
	SKELETON,
	ORC,
	TROLL,
};

struct Monster
{
	MONSTER type;
	std::string name;
	int health;
};

std::string b(Monster a)

{
	if (a.type == MONSTER::OGRE)
		return "Ogre";
	if (a.type == MONSTER::GOBLIN)
		return "Goblin";
	if (a.type == MONSTER::SKELETON)
		return "Skeleton";
	if (a.type == MONSTER::ORC)
		return "Orc";
	if (a.type == MONSTER::TROLL)
		return "Troll";

	return "Unknown";
}

void printMonster(Monster a)
{
	std::cout<< "This " << b(a)<< " is named " << a.name << " and has " << a.health << " health.\n";

}

int main()
{
	Monster goblin{ MONSTER::GOBLIN, "Ivan",200 };
	Monster orc{ MONSTER::ORC, "LOX", 55 };
	printMonster(goblin);
	printMonster(orc);
	return 0;

}
