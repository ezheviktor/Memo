# include <iostream>

void firstFrase()
{
	std::cout << "Wanna hear a joke?" << std::endl;
}

int programAnswer1()
{
	std::cout << "Kolobok hang himself)))" << std::endl;
	return 0;
}

int programAnswer2()
{
	std::cout << " Fine, anyway i dont like you" << std::endl;
	return 0;
}

int userAnswer()
{
	std::cout << "Enter your answer (1= yes, 2= no):";
	int answer;
	std::cin >> answer;
	return answer;
}

int determination(int answer)
{
	if (answer == 1)
		return programAnswer1();
	if (answer == 2)
		return programAnswer2();


}

int main()
{
	firstFrase();
	int input = userAnswer();
	determination(input);


}


