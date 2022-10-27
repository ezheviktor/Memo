#include <iostream>
#include <string>

/* int main()
{
	int array[] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
	int numStudents = sizeof(array) / sizeof(array[0]);
	
	for (int people = 0; people < numStudents; ++people)
	{
		std::cout << "The " << people + 1 << " element of array is: " << array[people]<<std::endl;
	}
	return 0;
}

int main()
{
	int array[] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
	int numStudents = sizeof(array) / sizeof(array[0]);

	while (true)
	{
		std::cout << "Enter the number from 1 to 9: \n";
		int number;
		std::cin >> number;

		if (number<1||number>9)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
		{
			for (int people = 0; people < numStudents; ++people)
			{
				std::cout << "The " << people + 1 << " element of array is: " << array[people] << std::endl;
			}
			for (int index = 0; index < numStudents; ++index)
			{
				if (array[index] == number)
				{
					std::cout << index << std::endl;
					break;
				}
			}
			break;
		}
	}
}*/





int main()
{
	int students[] = { 73, 85, 84, 44, 78 };
	const int numStudents = sizeof(students) / sizeof(students[0]);

	int maxScore=0;
	int maxIndex=0;

	for (int person = 0; person < numStudents; ++person)
		if (students[person] > maxScore)
		{
			maxScore = students[person];
			maxIndex = person;
		}

	std::cout << "The highest score has index " << maxIndex << '\n';

	return 0;
}