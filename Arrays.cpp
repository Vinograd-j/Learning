#include <iostream>

using namespace std;

int random(int a, int b);
int* filter(int* array, size_t size, size_t& filteredSize);

int main() {

	int const size = 30;

	int array[size] { 0 };
	
	for (size_t i = 0; i < size; i++)
		*(array + i) = random(10, 50);

	for (size_t i = 0; i < size; i++)
		cout << *(array + i) << endl;
	
	cout << '\n';

	size_t filteredSize = 0;
	int* filtered = filter(array, size,filteredSize);

	for (size_t i = 0; i < filteredSize; i++)
		cout << *(filtered + i) << endl;

	delete[] filtered;

	return 0;
}

int random(int a, int b)
{
	return (rand() % (b - a + 1)) + a;
}

int* filter(int* array,  size_t size, size_t& filteredSize)
{
	int* filtered = new int[size];
	int* p = new int();
	delete p;

	for (size_t i = 0; i < size; i++)
		if (array[i] >= 10 && array[i] <= 20) 
			filtered[filteredSize++] = array[i];
	
	return filtered;
}