#include <iostream>
#include <string>
#include <cstdlib> // для rand() и srand()
#include <ctime>
//
//class Fruit
//{
//	std::string m_name;
//	std::string m_color;
//public:
//	Fruit(std::string color = " ",std::string name= " "):m_name(name),m_color(color){}
//	std::string getName() { return m_name;}
//	std::string getColor() { return m_color; }
//};
//
//class Apple: public Fruit
//{
//public:
//	Apple(std::string color = "wasnt mentioned",std::string name="apple" ):Fruit(color,name){}
//};
//
//class Banana : public Fruit
//{
//public:
//	Banana( std::string color="yellow",std::string name = "banana") :Fruit( color, name ) {}
//};
//
//class GrannySmith :public Apple
//{
//	std::string m_person;
//public:
//	GrannySmith(std::string color = "green", std::string name = "Granny Smith apple"):Apple(color, name){}
//};
//
//int main()
//{
//	Apple a("red");
//	Banana b;
//	GrannySmith c;
//
//	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
//	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
//	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
//
//	return 0;
//}

using namespace std;

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем генерацию значения из диапазона
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;
public:
	Creature(std::string name,char symbol,int health,int damage,int gold):m_name(name),m_symbol(symbol),m_health(health),
	m_damage(damage),m_gold(gold){}

	std::string getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int getHealth() { return m_health; }
	int getDamage() { return m_damage; }
	int getGold() { return m_gold; }

	void reduceHealth(int reduce) {m_health -= reduce;}
	bool isDead() 
	{
		if (m_health <= 0) return true;
		else return false;
	}
	void addGold(int add) { m_gold += add; }
};

class Player : public Creature
{
	int m_level;
public:
	Player( std::string name, char symbol='@', int health=10, int damage=1, int gold=0, int level = 1 ):m_level(level),
		Creature(name,symbol,health,damage,gold){}

	void levelUp() { ++m_level; ++m_damage; }
	bool hasWon() { if (m_level == 20) return true; else return false; }
	int getLevel() { return m_level; }

};

class Monster : public Creature
{
public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES,
	};
	struct MonsterData
	{
		std::string name; 
		char symbol;
		int health;
		int damage;
		int gold;
	};

	static MonsterData monsterData[MAX_TYPES];
	Monster(Type type): Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health,
		monsterData[type].damage, monsterData[type].gold){}
	static Monster getRandomMonster() { return Monster(static_cast<Type>(getRandomNumber(0, MAX_TYPES - 1))); }
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

void attackPlayer(Player &example,Monster &myMonster)
{
	example.reduceHealth(myMonster.getDamage());
	cout << "You were hit by the " << myMonster.getName() << " for " << myMonster.getDamage() << " damage.\n";
	if (example.getHealth() <= 0)
		std::cout << "You were killed.\n";
	else
		cout << "Now your health is " << example.getHealth() << "." << endl;
	
}

void attackMonster(Player &example, Monster &myMonster)
{
	myMonster.reduceHealth(example.getDamage());
	cout << "You hit the " << myMonster.getName() << " for " << example.getDamage() << " damage.\n";
	if (myMonster.getHealth() <= 0)
		std::cout << "You killed the monster. Now your health is "<<example.getHealth()<<endl;
	else
		cout << "Now monster health is: " << myMonster.getHealth() << "\n";
}

void fightMonster(Player &example, int &strangeIndex)
{
	Monster myMonster = Monster::getRandomMonster();
	std::cout << "You have encountered a " << myMonster.getName() << " (" << myMonster.getSymbol() <<")" << endl;
	cout<<"\n Do you want to(R)un or (F)ight ? " <<  endl;
	std::string choice;
	cin >> choice;
	
	if (choice == "r"||choice=="R")
	{
		int success = getRandomNumber(1, 2);
		if (success == 1)
		{
			cout << "You successfully fled!\n";
		}
		else
		{
			cout << "Failed to flee! Monster caught you( Now you have to fight" << endl;
			for (; myMonster.isDead() == false && example.isDead() == false;)
			{
				attackPlayer(example, myMonster);
				if (example.isDead() == true)
				{
					goto end;
				}
				attackMonster(example, myMonster);
				cout << "\n Do you want to(R)un or (F)ight ? " << endl;
				std::string choice2;
				cin >> choice2;
				
			}
		}
	}
	else if(choice=="f"||choice=="F")
	{
		for (; myMonster.isDead() == false&&example.isDead()==false;)
		{
			attackMonster(example, myMonster);
			if (myMonster.isDead() == true)
			{
				goto end;
			}
			attackPlayer(example, myMonster);
		}
	}
	else
	{
		cout << "Try again please\n";
	}

	end:
	if (myMonster.isDead()==true)
	{
		strangeIndex = 0;
		example.levelUp();
		example.addGold(myMonster.getGold());
		std::cout << "You are now level " << example.getLevel() << ".\n You found " << myMonster.getGold() << " gold.\n";
	}
	else if (example.isDead()==true)
	{
		strangeIndex = 1;
		cout << "you died at level " << example.getLevel() << " and with " << example.getGold() << " gold.\n";
	}
	
	if (example.hasWon()==true)
	{
		strangeIndex = 2;
		cout << "Congratulations!! you have reached level 20. Good luck!\n";
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	rand(); // сбрасываем первый результат

	std::cout << "What is your name? ";
	string playerName;
	cin >> playerName;
	Player first(playerName);
	std::cout << "Welcome, " << first.getName() << "!\n";
	int strangeIndex=0;

	

	while (strangeIndex==0)
	{
		fightMonster(first, strangeIndex);
	}
	return 0;
}