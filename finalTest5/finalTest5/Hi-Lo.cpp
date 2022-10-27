#include <iostream>
#include "constants.h"
#include <cmath>
#include <math.h>
#include <random>
#include <ctime>

int getRandomNumber(int min, int max)
{
    srand(static_cast<int>(time(0)));
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}



void usersValues(int a)

{
    setlocale(LC_CTYPE, "ukr");



    int count;
    int attempts=7;

    for (count = 0; count < 7; ++count)
    {
        std::cout << "Введи своє число: ";
        int16_t value;
        std::cin >> value;
        --attempts;

        if (value == a)
        {
            std::cout << "Ти вгадав аж з " << 7 - attempts << " спроби. Хоча це все одноо краще ніж з ніякої. Вітаю ти беззмістовно витратив ще одну хвилину свого життя.\n";
            break;
        }

        else if (value <= a + 2 && value >= a - 2)
            std::cout << "Ще трохи... У тебе +-2. У тебе залишилося " << attempts << " спроб.\n";
        else if (value <= a + 5 && value >= a - 5)
            std::cout << "Нормально так навалюєш, краще б у тебе на гроші такий нюх був. Ти вже в радіусі 5 від цілі \t:o3\t  У тебе залишилося " << attempts << " спроб.\n";
        else if (value <= a + 10 && value >= a - 10)
            std::cout << "Ооооого! а ти не такий невдаха як здається, ти вже близько (+-10) , але ж ми обоє знаємо що ти програєш). Спробуй ще раз. У тебе залишилося " << attempts << " спроб.\n";
        else if (value <= a + 20 && value >= a - 20)
            std::cout << "Сьогодні в Лас-Вегас їхати не рекомендую (+-20). У тебе залишилося " << attempts << " спроб.\n";
        else if (value <= a + 25 && value >= a - 25)
            std::cout << "чувак ти що смієшся?  (+-25)\t -_-\t З такою фортуною тобі світить максиум пів шишечки) Я не шуткую, краще б пішов убився, ти реально лох, \n Хоча якщо захочеш спробувати ще раз то будь ласка) У тебе залишилося " << attempts << " спроб.\n";
        else if (value >= a - 40 && value <= a + 40)
            std::cout << "Взагалі не туди (+-40).  У тебе залишилося " << attempts << " спроб.\n";

    }
    std::cout << "Не вгадав, число було: " << a<<std::endl;


}

int main()
{
    setlocale(LC_CTYPE, "ukr");
    using namespace std;
    cout << "Давай зіграємо в гру. Я прилдумаю число від 1 до 100 а ти спробуєш його вгадати) У тебе 7 спроб. Я даватиму тобі підказки, але не думаю що такому як ти це допоможе.... \nЩо ж розпочнемо." << endl;

    std::random_device rd;
    std::mt19937 mersenne(rd());

    start:
    int compValue = mersenne();

    if (compValue <= 100 && compValue >= 1)
    {
        usersValues(compValue);
        std::cout << "Якщо надумаєш зіграти ще раз тисни y або n. я завжди буду тобі не радий)))";
        while (true)
        {
            char b;
            std::cin >> b;
            std::cin.ignore(37627, '\n');
            if (b == 'y' || b == 'n')
            {
                std::cout << "Капец знову)))\n";
                goto start;
            }
            else
                std::cout << "Ну і фіг з ним, іди краще чаю попий, якщо захочеш зіграти тикай у або n\n";
        }
    }
    else
        goto start;
    return 0;
    
}