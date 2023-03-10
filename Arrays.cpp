#include <iostream>

int randomom(int a, int b);
int* filter(int* array, size_t size, size_t& filteredSize);

int maaadin() {

	int const size = 30;

	int array[size]{ 0 };

	for (size_t i = 0; i < size; i++)
		*(array + i) = randomom(10, 50);

	for (size_t i = 0; i < size; i++)
		std::cout << *(array + i) << std::endl;

	std::cout << '\n';

	size_t filteredSize = 0;
	int* filtered = filter(array, size, filteredSize);

	for (size_t i = 0; i < filteredSize; i++)
		std::cout << *(filtered + i) << std::endl;

	delete[] filtered;

	return 0;
}

int randomom(int a, int b)
{
	return (rand() % (b - a + 1)) + a;
}

int* filter(int* array,  size_t size, size_t& filteredSize)
{
	int* filtered = new int[size];

	for (size_t i = 0; i < size; i++)
		if (array[i] >= 10 && array[i] <= 20) 
			filtered[filteredSize++] = array[i];
	
	return filtered;
}