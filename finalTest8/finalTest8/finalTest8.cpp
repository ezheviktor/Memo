#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <random>
#include <cstdlib>
#include <ctime>
#include <array>

//class Point
//{
//	double m_a;
//	double m_b;
//public:
//	Point(double a = 0.0, double b = 0.0):m_a(a),m_b(b) {}
//	void print()
//	{
//		std::cout <<"Point("<< m_a << ", " << m_b<<")\n";
//	}
//	friend double distanceFrom(const Point& a,const Point& b);
//};
//
//double distanceFrom(const Point& a,const Point& b)
//{
//	return sqrt((a.m_a - b.m_a) * (a.m_a - b.m_a) + (a.m_b - b.m_b) * (a.m_b - b.m_b));
//}
//
//int main()
//{
//	Point first;
//	Point second(2.0, 5.0);
//	first.print();
//	second.print();
//	std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
//
//	return 0;
//}

//class Welcome
//{
//private:
//	char* m_data;
//
//public:
//	Welcome()
//	{
//		m_data = new char[14];
//		const char* init = "Hello, World!";
//		for (int i = 0; i < 14; ++i)
//			m_data[i] = init[i];
//	}
//
//	~Welcome()
//	{
//		delete[] m_data;
//		m_data = nullptr;
//	}
//
//	void print() const
//	{
//		std::cout << m_data;
//	}
//
//};
//
//int main()
//{
//	Welcome hello;
//	hello.print();
//
//	return 0;
//}

//class Monster
//{
//public:
//	enum MonsterType
//	{
//		Dragon,
//		Goblin,
//		Ogre,
//		Orc,
//		Skeleton,
//		Troll,
//		Vampire,
//		Zombie,
//		MAX_MONSTER_TYPES,
//	};
//private:
//	std::string m_name;
//	int m_health;
//	MonsterType m_type;
//public:
//	Monster(Monster::MonsterType type,std::string name,int health):m_name(name),m_health(health),m_type(type){}
//	std::string getTypestring()
//	{
//		switch (m_type)
//		{
//		case Monster::Dragon: return "Dragon";
//		case Monster::Goblin: return "Goblin";
//		case Monster::Ogre: return "Ogre";
//		case Orc: return "Orc";
//		case Skeleton: return "Skeleton";
//		case Troll: return "Troll";
//		case Vampire: return "Vampire";
//		case Zombie: return "Zombie";
//		}
//	}
//	void print()
//	{
//		std::cout << m_name << " is " << getTypestring() << " and has " << m_health << " health points.\n";
//	}
//	friend class MonsterGenerator;
//};
//
//class MonsterGenerator
//{
//public:
//	
//	static Monster generateMonster()
//	{
//		Monster::MonsterType m_type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
//		int randomHealth = getRandomNumber(1, 100);
//		static std::string s_name[6] {"Steve","Alex","Vika","Frank","Oleg","Johnatan"};
//		return 	Monster{ m_type, s_name[getRandomNumber(0,5)], randomHealth};
//	}
//	static int getRandomNumber(int min, int max)
//	{
//		static const double fraction = 1 / (static_cast<double>(RAND_MAX) + 1.0);
//		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
//	}
//};
//
//int main()
//{
//	srand(static_cast<unsigned int>(time(0))); 
//	rand(); 
//
//	Monster m = MonsterGenerator::generateMonster();
//	m.print();
//
//	return 0;
//}





class Card
{
public:
	enum CardSuit
	{
		SUIT_CLUB,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_SPADE,
		MAX_SUITS
	};
	enum CardRank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANKS
	};
private:
	CardRank m_rank;
	CardSuit m_suit;
public:
	Card(Card::CardRank a=MAX_RANKS, Card::CardSuit b=MAX_SUITS):m_rank(a),m_suit(b){}
	void printCard() const
	{
		switch (m_rank)
		{
		case RANK_2:		std::cout << '2'; break;
		case RANK_3:		std::cout << '3'; break;
		case RANK_4:		std::cout << '4'; break;
		case RANK_5:		std::cout << '5'; break;
		case RANK_6:		std::cout << '6'; break;
		case RANK_7:		std::cout << '7'; break;
		case RANK_8:		std::cout << '8'; break;
		case RANK_9:		std::cout << '9'; break;
		case RANK_10:		std::cout << 'T'; break;
		case RANK_JACK:		std::cout << 'J'; break;
		case RANK_QUEEN:	std::cout << 'Q'; break;
		case RANK_KING:		std::cout << 'K'; break;
		case RANK_ACE:		std::cout << 'A'; break;
		}

		switch (m_suit)
		{
		case SUIT_CLUB:		std::cout << 'C'; break;
		case SUIT_DIAMOND:	std::cout << 'D'; break;
		case SUIT_HEART:	std::cout << 'H'; break;
		case SUIT_SPADE:	std::cout << 'S'; break;
		}
	}
	int getCardValue()
	{
		switch (m_rank)
		{
		case RANK_2:		return 2;
		case RANK_3:		return 3;
		case RANK_4:		return 4;
		case RANK_5:		return 5;
		case RANK_6:		return 6;
		case RANK_7:		return 7;
		case RANK_8:		return 8;
		case RANK_9:		return 9;
		case RANK_10:		return 10;
		case RANK_JACK:		return 10;
		case RANK_QUEEN:	return 10;
		case RANK_KING:		return 10;
		case RANK_ACE:		return 11;
		}

		return 0;
	}
};


class Deck
{
private:
	std::array<Card, 52> m_deck;
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить только один раз
		// Равномерно распределяем вычисление значения из нашего диапазона
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
	static void swapCard(Card& a, Card& b)
	{
		Card temp = a;
		a = b;
		b = temp;
	}
	int m_cardIndex = 0;

public:
	Deck()
	{
		int card = 0;
		for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
			for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
			{
				m_deck[card] = Card( static_cast<Card::CardRank>(rank),static_cast<Card::CardSuit>(suit) );
				++card;
			}
	}
	void printDeck() const
	{
		for (const auto& card : m_deck)
		{
			card.printCard();
			std::cout << ' ';
		}
		std::cout << '\n';
	}
	void shuffleDeck()
	{
		// Перебираем каждую карту в колоде
		for (int index = 0; index < 52; ++index)
		{
			// Выбираем любую случайную карту
			int swapIndex = getRandomNumber(0, 51);
			// Меняем местами с нашей текущей картой
			swapCard(m_deck[index], m_deck[swapIndex]);
		}
		m_cardIndex = 0;
	}
	Card& dealCard()
	{
		return m_deck[m_cardIndex++];
	}
};


char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

bool playBlackjack()
{
	Deck myDeck;
	myDeck.shuffleDeck();

	int playerTotal = 0;
	int dealerTotal = 0;

	// Дилер получает одну карту
	dealerTotal += myDeck.dealCard().getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// Игрок получает две карты
	playerTotal += myDeck.dealCard().getCardValue();
	playerTotal += myDeck.dealCard().getCardValue();

	// Игрок начинает
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += myDeck.dealCard().getCardValue();

		// Смотрим, не проиграл ли игрок
		if (playerTotal > 21)
			return false;
	}

	// Если игрок не проиграл (у него не больше 21), тогда дилер получает карты до тех пор, пока у него в сумме будет не меньше 17
	while (dealerTotal < 17)
	{
		dealerTotal += myDeck.dealCard().getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// Если у дилера больше 21 - он проиграл. Игрок выиграл
	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
	rand(); // пользователям Visual Studio: делаем сброс первого случайного числа

	
	if (playBlackjack())
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";

	return 0;
}