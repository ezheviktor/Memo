#include <iostream>
#include <string>

int sumTo(const int a)
{
	static int sum;
	for (int i = 1; i < a; ++i)
	{
		sum += i;
	}
	return sum;
}


void printAnimalName(struct Animal& animal);
void minmax(const int a, const int b, int& minOut, int& maxOut);
void getIndexOfLargestValue(const int* array, const int length);
const int& getElement(const int* array, const int index);