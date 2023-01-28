#include <iostream>

using namespace std;

int random(int a, int b);
int* filter(int array[], int size);

int main() {

	srand(time(NULL));

	const int size = 10;

	int array[size];

	for (size_t i = 0; i < size; i++)
		array[i] = random(1,20);

	for (size_t i = 0; i < size; i++)
		cout << array[i] << endl;
	
	cout << endl;

	int* filtered; 
	filtered = filter(array, size);

	for (size_t i = 0; i < size; i++)
		cout << filtered[i] << endl;

	return 0;
}

int random(int a, int b) {
	return (rand() % (b - a + 1)) + a;
}

int* sort(int array[], int size)
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
	return array;
}
