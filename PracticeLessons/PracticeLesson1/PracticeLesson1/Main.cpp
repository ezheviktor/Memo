#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <math.h> /* математичні функції */
#include <set>

using namespace std;

//first task

//bool falseTypes ( std::string str)
//	{
//		std::vector<char> myVec;
//		int counter = 0;
//		for (int i=0;i<str.length();++i)
//		{
//			if (std::find(myVec.begin( ), myVec.end( ), str[i]) == myVec.end())
//				myVec.push_back(str[i]);
//			if ((i >= 1) && (str[i] != str[i - 1]))
//				++counter;
//		}
//		return myVec.size( ) > 2||counter!=2;
//	}
//
//bool checkSandwich( std::string str)
//{
//	if ((str.length( ) < 3)|| falseTypes(str))
//		return false;
//		
//
//	while (str.length() != 1 && str.length( ) != 0)
//	{
//		if (str[0] != str[str.length( ) - 1])
//			return false;
//		str.erase(0,1);
//		str.erase(str.length( ) - 1, 1);
//	}
//	return true;
//	
//}
//
//int main(int argc, char* argv[])
//{
//	while (1)
//	{
//		std::cout << "\nPlease, enter a sandwich: ";
//		std::string input;
//		cin >> input;
//
//		if (checkSandwich(input))
//		{
//			std::cout << "\nYou entered a sandwich " << input << endl;
//			cout << "\nDo you want to retry?(1-yes;0-no):";
//			int in;
//			cin >> in;
//			if(!in)
//				break;
//		}
//		else
//		cout << "\nIt`s not a sandwich(((";
//
//	}
//	return 0;
//}

int main( )
{
	
	bool cycle = 1;
	std::set<int> set;
	while(cycle)
	{
		std::cout << "Enter a vector of positive numbers";
		int temp;

		while (cin >> temp)
		{
			if (temp > 0)
			{
				set.insert(temp);
				char add = cin.get( );
				if (add == '\n') { cycle = 0; break; }
			}
			else
			{
				set.clear( );
				cin.ignore(32767,'\n');
				break;
			}
		}
	}
	std::set<int>::iterator t= set.cbegin( );
	std::advance(t, 1);

	
	std::cout <<*t<< endl;
}
