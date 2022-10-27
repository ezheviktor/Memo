#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string array[] = { "Sasha","Ivan","John","Orlando","Leonardo","Nina","Anton","Molly" };
	while (true)
	{
		cout << "Please enter the name: ";
		string line;
		getline(cin, line);
		bool statement = true;
		for (const auto& element : array)
		{
			if (element == line)
			{
				cout << "\nThe name is found.\n";
				statement = false;
				break;
			}
		}
		if (statement)
			cout << "\n"<<line << " was not found.\n";
	}
	return 0;
}
