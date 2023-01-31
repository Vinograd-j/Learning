#include <iostream>
#include "Functions.h"

using namespace std;

void filter(int* array, int size);
void printArray(int* array, int size);

int msdfain() {

	const int size = 10;

	int array[size];

	for (size_t i = 0; i < size; i++)
		array[i] = random(1,20);

	printArray(array,size);
	
	cout << endl;

	filter(array, size);

	printArray(array, size);

	return 0;
}


void filter(int* array, int size)
{
	int temp;

	for (size_t i = 0; i < size-1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (array[j] % 2 != 0)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void printArray(int* array, int size) {
	for (size_t i = 0; i < size; i++)
		cout << array[i] << endl;
}