#include <iostream>
#include "vector.h"

#define PRINTLN(x) std::cout << (x) << std::endl

int* CreateMatrix(size_t rows, size_t columns)
{
	size_t size = rows * columns;

	return new int[size];
}

void PrintMatrix(int* matrix, size_t rows, size_t columns)
{
	for (size_t y = 0; y < rows; ++y)
	{
		for (size_t x = 0; x < columns; ++x)
		{

			std::cout << matrix[y * columns + x] << " ";

		}

		std::cout << '\n';
	}

}

int main() {


	auto matrix = CreateMatrix(10, 10);

	matrix[0] = 1;
	matrix[1] = 8;
	matrix[2] = 24;
	matrix[3] = 48;

	PrintMatrix(matrix, 10, 10);

 //    Vector<int> v1 {0, 5, 9 ,8, 7, 10548, 228};
 //
	// Vector<int> v2{ 1, 3, 5 };
	//
	// auto v3 = (v1 = v2);
 //
	// PRINTLN(v1);
	// PRINTLN(v2);
}
