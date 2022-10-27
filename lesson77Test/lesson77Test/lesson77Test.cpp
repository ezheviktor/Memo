#include <iostream>
#include <utility>

/*int main()
{
	const int length = 5;
	int array[length] = { 30, 50, 20, 10, 40 };

	for (int startIndex=0; startIndex < length - 1; ++startIndex)
	{
        int biggestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex<length;++currentIndex)
		{
			if (array[currentIndex] > array[biggestIndex])
			    biggestIndex = currentIndex;

		}
		std::swap(array[startIndex], array[biggestIndex]);
	}
	for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';
	return 0;
}*/

/*int main()
{
    const int length = 5;
    int array[length] = { 30, 50, 20, 10, 40 };

    // Перебираем каждый элемент массива, кроме последнего
    for (int startIndex = 0; startIndex < length - 1; ++startIndex)
    {
        // largestIndex - это индекс наибольшего элемента, который мы обнаружили до сих пор
        int largestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            // Если текущий элемент больше нашего наибольшего элемента,
            if (array[currentIndex] > array[largestIndex])
                // то это новый наибольший элемент в этой итерации
                largestIndex = currentIndex;
        }

        // Меняем местами наше стартовое число с обнаруженным наибольшим элементом
        std::swap(array[startIndex], array[largestIndex]);
    }

    // Выводим отсортированный массив на экран
    for (int index = 0; index < length; ++index)
        std::cout << array[index] << ' ';

    return 0;
}*/

int main()
{
    const int length(9);
    int array[length] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
    
    for (int num = 0; num < length-1; ++num)
    {
        
       
            int b = num + 1;
            for(b;b<length;++b)
            if (array[num] > array[b])
            {
                std::swap(array[num], array[b]);

            }
            

        
    }
    for (int i = 0; i < length; ++i)
    {
        std::cout << array[i] << " ";
    }
    return 0;
}