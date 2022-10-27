#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <functional>


double max(const double& a, const double& b);
void swap(int& a, int& b);
int& getLargestElement(std::vector<int>& a, int length);

int binarySearch(int* array, int target, int min, int max)
{
	bool stopCycle(true);
	while (stopCycle)
	{
		int middle = (max + min ) / 2;
		if ((max - min) <= 1)
		{
			stopCycle=0;
			return min;
		}
		else if (array[middle] == target)
		{
			stopCycle = 0;
			return middle;
		}
		else if (array[middle] > target)
		{
			max = middle;
		}
		else if (array[middle] < target)
		{
			min = middle;
		}
	}

}
int binarySearch2(int* array, int target, int min, int max)
{
	bool stopCycle(false);
	int middle = (max + min) / 2;
	if ((max - min) <= 1)
	{
		stopCycle = 0;
		return min;
	}
	else if (array[middle] == target)
	{
		stopCycle = 1;
		return middle;
	}
	else if (array[middle] > target)
	{
		max = middle;
		return binarySearch2(array,target,min,max);
	}
	else if (array[middle] < target)
	{
		min = middle;
		return binarySearch2(array, target, min, max);
	}
}

int main()
{
	int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };

	std::cout << "Enter a number: ";
	int x;
	std::cin >> x;

	int index = binarySearch2(array, x, 0, 14);

	if (array[index] == x)
		std::cout << "Good! Your value " << x << " is on position " << index << " in array!\n";
	else
		std::cout << "Fail! Your value " << x << " isn't in array!\n";
	return 0;
}