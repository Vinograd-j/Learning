#include "Functions.h"
#include <iostream>

bool _isInit = false;

int random(int a, int b)
{
    if (!_isInit) {
        srand(time(0));
        _isInit = true;
    }

    return (rand() % (b - a + 1)) + a;
}


int* setOfUnion(int first[], int firstSize, int second[], int secondSize, int& unionSize) {

    int* total = new int[firstSize + secondSize];

    std::copy(first, first + firstSize, total);

    int freeIndex = firstSize;

    for (size_t i = 0; i < secondSize; i++)
    {
        if (!contains(first, firstSize, second[i]))
            total[freeIndex++] = second[i];
    }

    unionSize = freeIndex;

    return total;
}

bool contains(int* array, int size, int element) {

    for (size_t i = 0; i < size; i++)
        if (array[i] == element)
            return true;

    return false;
}
