#include <iostream>
#include <string>
#include <cmath>

static struct Advertising
{
	int16_t shown;
	double percentsClicked;
	double earnedAtOnce;
};

int main()
{
	std::cout << "Enter the amount of shown advertisements: \n";
	int16_t shown;
	std::cin >> shown;

	std::cout << "Enter the percentage of Clicked adverisements if 100% are 1: \n";
	double percentsClicked;
	std::cin >> percentsClicked;

	std::cout << "Enter the amount of money you earn for 1 clicked advertisement: \n";
	double earnedAtOnce;
	std::cin >> earnedAtOnce;

	Advertising mySite{ shown,percentsClicked,earnedAtOnce };
	std::cout << "You shown " << mySite.shown << " advertisements,\n";
	std::cout << mySite.percentsClicked << " of all advertisements were clicked,\n";
	std::cout << "From one clicked advertisement you earn " << mySite.earnedAtOnce << " bucks.\n";
	std::cout << '\n';
	std::cout << "Today you have earned: " << mySite.shown * mySite.percentsClicked * mySite.earnedAtOnce << " bucks)))"<<std::endl;
	return 0;
}