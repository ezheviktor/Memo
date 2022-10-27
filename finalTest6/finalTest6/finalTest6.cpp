#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <random>
#include <ctime>

/*enum Items
{
	MEDICINE=0,
	TORCHES,
	ARROWS,
	TOTAL,
};

int Total(int array[])
{
	return array[Items::MEDICINE] + array[Items::ARROWS] + array[Items::TORCHES];
}

int main()
{
	int myArray[Items::TOTAL]{ 3,6,12 };
	std::cout << "The total number of items is: " << Total(myArray)<<std::endl;
	return 0;
}*/

/*struct Students
{
	std::string name;
	int mark;
};

int sort(Students*array[],int a)
{
	for (int index = 0; index < a-1; ++index)
	{
		int biggestIndex = index;
		for (int current = index + 1; current < a; ++current)
		{
			if (array[current] > array[index])
				biggestIndex = current;
		}
		std::swap(array[biggestIndex], array[index]);
	}
}

int main()
{
	using namespace std;

	cout << "How many students do you want to enter? \n";
	int amountOfStudents;
	cin >> amountOfStudents;

	Students* array = new Students[amountOfStudents];
	
	for (int i = 0; i < amountOfStudents; ++i)
	{
		cout << "Enter the name of the student: \n";
		cin >> array[i].name;
		cin.ignore(32767, '\n');
		cout << "Enter the mark of the student: \n";
		cin >> array[i].mark;
		cin.ignore(32767, '\n');
	}

	for (int index = 0; index < amountOfStudents - 1; ++index)
	{
		int biggestIndex = index;
		for (int current = index + 1; current < amountOfStudents; ++current)
		{
			if (array[current].mark > array[index].mark)
				biggestIndex = current;
		}
		std::swap(array[biggestIndex].name, array[index].name);
		std::swap(array[biggestIndex].mark, array[index].mark);
	}

	for(int myI=0;myI<amountOfStudents;++myI)
	{
		cout << "\n"<< array[myI].name << " got a grade of " << array[myI].mark << std::endl;
	}

	delete[] array;
	array = 0;

	return 0;
}*/

/*
void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
int main()
{
	using namespace std;
	cout << "Enter a and b: \n";
	int a, b;
	cin >> a >> b;
	cout << "Before swap a= " << a << " and b= " << b << endl;
	swap(a, b);
	cout<< "After swap a= " << a << " and b= " << b << endl;
	return 0;
}*/

/*
void function(const char*a[])
{
	for (const char *i = a[0]; *i != '\0'; ++i)
		std::cout << *i << " ";
}

int main()
{
	const char* array[]={ "Hello world!" };
	const char* ptr = array[0];
	function(array);
	return 0;
}*/

enum Type
{
	TREFF,
	BUBNA,
	CHIRVA,
	PIKA,
	TOTAL,
};

enum Distinguishes
{
	CARD2,
	CARD3,
	CARD4,
	CARD5,
	CARD6,
	CARD7,
	CARD8,
	CARD9,
	CARD10,
	VALET,
	DAMA,
	KING,
	TUTH,
	TOTAl,
};

struct Card
{
	Distinguishes distinguish;
	Type type;
};

void printCard(const Card &a )
{
	using namespace std;
	switch (a.distinguish)
	{
	case CARD2: cout << "2"; break;
	case CARD3: cout << "3"; break;
	case CARD4: cout << "4"; break;
	case CARD5: cout << "5"; break;
	case CARD6: cout << "6"; break;
	case CARD7: cout << "7"; break;
	case CARD8: cout << "8"; break;
	case CARD9: cout << "9"; break;
	case CARD10: cout << "10"; break;
	case VALET: cout << "V"; break;
	case DAMA: cout << "D"; break;
	case KING: cout << "K"; break;
	case TUTH: cout << "T"; break;
	}
	switch (a.type)
	{
	case TREFF: cout << "T"; break;
	case BUBNA: cout << "B"; break;
	case CHIRVA: cout << "C"; break;
	case PIKA: cout << "P"; break;
	}
}

void printDeck(const std::array<Card,52> &deck )
{
	for (const Card &card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}
}

void swapCard(Card &deck1,Card &deck2)
{
	std::swap(deck1.distinguish, deck2.distinguish);
	std::swap(deck1.type, deck2.type);
}

/*void shuffleDeck(std::array<Card,52> &deck)
{
	
	std::random_device rd;
	std::mt19937 mersenne(rd());

	for (int i = 0; i < 52; ++i)
	{
		start:
		int randomCard = mersenne();
		if (randomCard >= 52 || randomCard < 0)
			goto start;
		
		swapCard(deck[randomCard], deck[i]);
	}
}*/

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем генерацию случайного числа в диапазоне значений
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52>& deck)
{
	// Перебираем каждую карту в колоде
	for (int index = 0; index < 52; ++index)
	{
		// Выбираем любую случайную карту
		int swapIndex = getRandomNumber(0, 51);
		// Меняем местами с нашей текущей картой
		swapCard(deck[index], deck[swapIndex]);
	}
}

int getCardValue(Card &a)		
{
	using namespace std;
	switch (a.distinguish)
	{
	case CARD2: return 2; 
	case CARD3: return 3; 
	case CARD4: return 4; 
	case CARD5: return 5; 
	case CARD6: return 6; 
	case CARD7: return 7; 
	case CARD8: return 8; 
	case CARD9: return 9; 
	case CARD10: return 10; 
	case VALET: return 10; 
	case DAMA: return 10; 
	case KING: return 10; 
	case TUTH: return 11; 
	}
}

bool checkScore(int a)
{
	if (a > 21)
		return true;
	else
		return false;
}

int playBlackJack(std::array<Card, 52>& deck)
{
	using namespace std;

	Card* cardPtr = &deck[0];
	int playerScore=0;
	int dealerScore=0;

	dealerScore += getCardValue(*cardPtr++);
	playerScore += getCardValue(*cardPtr++);
	playerScore += getCardValue(*cardPtr++);
	cout << "\nDealer got two cards!" << endl;
	cout << "One card is now opened, dealer got " << dealerScore << " points." << endl;
	cout << "You have got two cards, both cards are open, your got " << playerScore << " points." << endl;
	bool preFinish = false;
	bool lost = false;
	bool win = false;
	bool draw = false;
	bool stopCycle=true;

	cout << "If you wanna start game enter start\n";
	string wish;
	cin >> wish;
	if (wish == "start" || wish == "Start" || wish == "START")
	{
		cout << "You have just started the game.\n";
	}
	else
	{
		cout << "You have just left the game. Good luck) See you next time.\n";
		preFinish = true;
		goto end;
	}


	while (stopCycle)
	{

		//хід гравця
		cout << "Its your turn now. Do you want to hit or stand? Enter the chosen action: \n";
		string action;
		cin >> action;

		if (action == "stand")
		{
			cout << "You decide to stand. Your score for now is: " << playerScore << " \n";
		}
		else if (action == "hit")
		{
			playerScore += getCardValue(*cardPtr++);
			cout << "You have taken one more card, you got for now " << playerScore << " points.\n";

		}

	

		if (checkScore(playerScore))
		{
			lost = true;
			goto end;
		}
		else if (dealerScore >= 17)
		{
			cout << "It was your last try. Now lets calculate the results.\n";
			if (dealerScore > playerScore)
			{
				lost = true;
				goto end;
			}
			else if (dealerScore < playerScore)
			{
				win = true;
				goto end;
			}
			else if (dealerScore = playerScore)
			{
				draw = true;
				goto end;
			}
		}

		cout << "Now its dealer turn\n";
		// хід дилера
		if (dealerScore < 17)
		{
			dealerScore += getCardValue(*cardPtr++);
			cout << "Dealer got one more card. Now his score is " << dealerScore << " points" << endl;
			if (dealerScore > 21)
			{
				win = true;
				goto end;
			}
		}
		else
		{
			cout << "Dealer already has " << dealerScore << " points. He can not take new cards anymore. Its your turn one more time.\n";

		}
	}
end:
	if (win)
	{
		cout << "Congratulations, you won!\n";
		return true;
	}
	else if (lost)
	{
		cout << "Im sory, but you lost, better luck next time.\n";
		return false;
	}
	else if (draw)
	{
		cout << "Its a draw.\n";
		return false;
	}
	else if (preFinish)
	{
		return false;
	}

}

int main()
{
	using namespace std;
	srand(static_cast<unsigned int>(time(0)));
	rand();
	array<Card, 52> deck;

	int card = 0;
	for (int o = 0; o < Type::TOTAL; ++o)
	{
		for (int i = 0; i < Distinguishes::TOTAl; ++i)
		{
			deck[card].distinguish = static_cast<Distinguishes>(i);
			deck[card].type = static_cast<Type>(o);
			++card;
		}
	}
	printDeck(deck);
	shuffleDeck(deck);
	printDeck(deck);

	playBlackJack(deck);

	return 0;

}




