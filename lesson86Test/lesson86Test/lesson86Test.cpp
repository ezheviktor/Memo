#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;


/*int main()
{
	
	
	cout << "How many names do you wanna enter? "<<endl;
	int number;
	cin >> number;

	string* a = new string[number];


	for (int i = 0; i < number; ++i)			//дана функція присвоює елементам масиву а елементи масиву б. При цьому масиву б присвоюється ввід.
	{
	
		char* b= new char[];
	
		cout << "\nEnter the name #" << i + 1;
		cin>>b[30];
		a[i] = b[30];
	}

	for (int out = 0; out < number; ++out)
	{
		for (int in = 0; in < 30; ++in)
		{
			
		}
	}

	
	/*std::string* array= new std::string[number];
	
	for (int i = 0; i < number; ++i)
	{
		cout << "\nEnter name #" << i+1 << " :";
		char *x=new char[];
		std::cin >> *x;
	
		//std::getline (std::cin,array[i]);
	
		if (*x=='a')
			array[]
	}




	for (int b = 0; b < number; ++b)
	{
		cout << "\t"<<array[b];
	}

	return 0;
}*/

int main()
{
	cout << "How many names do you wanna enter? " << endl;
	int number;
	cin >> number;

	string* a = new string[number];
	for (int i = 0; i < number; ++i)
	{
		cout << "\nEnter the name #" << i + 1<<" ";
		cin >> a[i];
	}
	
	for (int b = 0; b < number; ++b)
	{
		cout << a[b]<<"\n";
	}

	for(int outer=0;outer<number;++outer)
	{
		int smallestIndex = outer;
		for (int inner = outer+1; inner < number; ++inner)
		{
			if (a[inner] < a[smallestIndex])
			{
				smallestIndex=inner;
				
			}
		}
		swap(a[outer], a[smallestIndex]);
	}
			
	//sort(a, a + number);

	cout << "\nHere is the sorted list:\n";

	for (int b = 0; b < number; ++b)
	{
		cout << a[b]<<"\n";
	}

		return 0;
}