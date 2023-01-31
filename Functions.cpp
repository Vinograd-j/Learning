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

bool isValid(char* str)
{
    int size = sizeOfString(str);

    int indexOfSpace = -1;

    for (size_t i = 0; i < size; i++)
    {
        if (str[i] == ' ') 
        {
            if (indexOfSpace != -1)
                return false;

            indexOfSpace = i;
        }
    }

    if (indexOfSpace == 0 || indexOfSpace == size - 1 || indexOfSpace == -1)
        return false;
    
    return true;
}

int sizeOfString(const char* str) {

    int index = 0;

    while (str[index] != '\0')
        index++;

    return index;
}