#include <iostream>

#include "Functions.h"

int main() {

	int first[] = { 1, 2, 3 };
	int second[] = { 3, 4, 5 };

	int totalSize;

	int* total = setOfUnion(
		first, sizeof(first)/sizeof(first[0]), 
		second, sizeof(second) / sizeof(second[0]),
		totalSize
	);

	for (size_t i = 0; i < totalSize; i++)
		std::cout << total[i] << std::endl;

	delete[] total;
}

