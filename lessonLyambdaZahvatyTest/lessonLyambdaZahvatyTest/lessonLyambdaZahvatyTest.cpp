#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <array>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

int getRandomNumber(int min, int max)
{
	static const double fraction = 1 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction *(max - min + 1) + min);
}

void initializeArray(int& start,const int amount, int generatedRand, std::vector<int> &myArray)
{
	for (int i = 0; i < amount; ++i)
	{
		myArray.push_back( start*start*generatedRand);
		++start;
	}
}

void checkIfFound(int& user,const int &amount, const int &iteration, bool &lost, std::vector<int>& myArray)
{
	if (std::find(myArray.begin(), myArray.end(), user) == myArray.end())
	{
		auto notFound{ std::min_element(myArray.begin(), myArray.end(), [&](int a,int b) {
			auto distance{std::abs(a - user) < std::abs(b - user)};
			return distance;
			}) };
		if (std::abs(*notFound-user) <= 4)
		{
			std::cout << user << " is wrong!" << " Try " << *notFound << " next time.\n";
			lost = true;
		}
		else
		{
			std::cout << user << " is wrong.\n";
			lost = true;
		}
	}
	else
	{
		std::cout << "Well done! " << amount - (iteration+1) << " element(s) left\n";
		myArray.erase(std::find(myArray.begin(), myArray.end(), user));
	}
}

int main()
{
	using namespace std;
	srand(time(0));
	rand();

	std::cout << "Start where? ";
	int start;
	cin >> start;
	cout << "\nHow many? ";
	int amount;
	cin >> amount;

	int generatedRand = getRandomNumber(2, 4);
	std::vector<int> myArray{};
	initializeArray(start, amount, generatedRand, myArray);

	cout << "I generated " << amount << " square numbers. Do you know what each number is after multiplying it by " << generatedRand << "?" << endl;
	bool lost = false;
	for (int i = 0; i < amount; ++i)
	{
		if (lost==true)
			break;
		cout << "Enter suggested number:\n> ";
		int user;
		cin>>user;

		checkIfFound(user, amount, i,lost, myArray);
	}
	if (lost != 1)
		std::cout << "congratulations! You win))"<<std::endl;
	return 0;

}
