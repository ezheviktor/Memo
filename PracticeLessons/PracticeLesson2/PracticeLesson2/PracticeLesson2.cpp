
#include <iostream>
#include <random>
#include <time.h>
#include <ctime>
#include <sstream>

using namespace std;

void divideNumberIntoDigits(const int toGuess, std::vector<int>& numbers)
{
	std::stringstream stream(ios::in|ios::out);
	std::string convertational;

	stream << toGuess;
	stream >> convertational;
	
	
	for (auto i : convertational)
	{
		stream.str(" ");
		stream.clear( );
		stream << i;
		int temp;
		stream >> temp;
		numbers.push_back(temp);
		
	}
	
}

void checkIfMatched(std::vector<int>& computer, std::vector<int>& user,int& counterMatched, int& positionMatched)
{
	for (int i = 0; i < computer.size( ); ++i)
	{
		if (std::find(computer.begin( ), computer.end( ), user[i]) != computer.end( ))
		{
			counterMatched++;
			std::vector<int>::iterator t = std::find(computer.begin( ), computer.end( ), user[i]);
			int distance = std::distance(computer.begin( ), t);
			if (computer[distance] == user[distance])
			{
				positionMatched++;
			}
		}
	}
}

int main( )
{
	std::random_device rd;
	std::mt19937 mersenne(rd( ));
	std::uniform_int_distribution<> ran(0, 999);

	int toGuess= ran(mersenne);
	std::vector<int> numbersComputer;
	divideNumberIntoDigits(toGuess, numbersComputer);

	bool win = 0;

	std::cout << "\nTry to guess a number. It consists out of " << numbersComputer.size( ) << " digits ("<<toGuess<<")";
	while (!win)
	{
	std::cout << "\nEnter your number: ";
	int input;
	cin >> input;
	std::vector<int> numbersUser;
	divideNumberIntoDigits(input, numbersUser);

	
	int counterMatched = 0;
	int positionMatched=0;
		checkIfMatched(numbersComputer, numbersUser, counterMatched, positionMatched);
		if (counterMatched == numbersComputer.size( ) && positionMatched == numbersComputer.size( ))
		{
			std::cout << "\nCongratulations! You`ve guessed the right number))" << endl;
			win = 1;
		}
		else
		{
			cout << "\nGuessed: " << counterMatched << "; On their places: " << positionMatched << ";\n";
		}

	}










}



