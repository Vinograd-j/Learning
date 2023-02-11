#include<iostream>

int charToInt(char c);
long digitsToNumber(const char* digits);
bool contains(const char* string, char symbol);
const char* substring(const char* string, int startIndex, int endIndex);
double parseNumber(const char* string);
double fractionToDouble(const char* digits);
int countOfSymbol(const char* string, char symbol);
int stringLength(const char* string);
std::pair<const char*, const char*> splitPair(const char* string, char spliterator);

int main() {

	const char* string = "-0.36546464848451231231564878";

	std::cout << parseNumber(string);

	return 0;
}


double parseNumber(const char* string) {

	int size = stringLength(string);

	bool isNegative = string[0] == '-';

	if (isNegative)
		string = substring(string, 1, size - 1);

	if (!contains(string, '.')) {
		auto result = (isNegative ? -1 : 1) * digitsToNumber(string);
		if (isNegative)
			delete[] string;
		return result;
	}

	auto split = splitPair(string, '.');

	auto result = (isNegative ? -1 : 1) * (digitsToNumber(split.first) + fractionToDouble(split.second));

	if (isNegative)
		delete[] string;

	delete[] split.first;
	delete[] split.second;

	return result;

}

double fractionToDouble(const char* digits) {
	return digitsToNumber(digits) / pow(10, stringLength(digits));
}

long digitsToNumber(const char* digits) {

	int size = stringLength(digits);
	long number = 0;

	for (size_t i = 0; i < size; i++)
	{
		int digit = charToInt(digits[i]);
		number += digit * pow(10, size - i - 1);
	}

	return number;
}

int charToInt(char c) {
	if (c < '0' || c > '9')
		throw "Symbol is`t a digit";

	return c - '0';
}

const char* substring(const char* string, int startIndex, int endIndex) {

	int size = stringLength(string);

	if (!(startIndex >= 0 && startIndex < size && endIndex >= startIndex && endIndex < size))
		throw "Index out of bounds exception";
	
	int newSize = endIndex - startIndex + 1;

	char* filtered = new char[newSize + 1];

	for (size_t i = 0; i < newSize; i++)
	{
		filtered[i] = string[startIndex + i];
	}

	filtered[newSize] = '\0';

	return filtered;
}

bool contains(const char* string, char symbol){
	
	int index = 0;

	while (string[index] != '\0')
		if (string[index++] == symbol)
			return true;
	
	return false;
}


int countOfSymbol(const char* string, char symbol) {

	int count = 0;

	for (size_t i = 0; i < stringLength(string); i++)
	{
		if (string[i] == symbol)
			count++;
	}
	return count;
}

int stringLength(const char* string)
{
	int index = 0;
	
	while (string[index++] != '\0');

	return index - 1;
}

typedef unsigned int uint32;

std::pair<const char*, const char*> splitPair(const char* string, char spliterator)
{
	int size = stringLength(string);

	int spliteratorIndex = -1;

	for (uint32 i = 0; i < size; i++)
	{
		char c = string[i];
		
		if (c == spliterator) {
			
			if (spliteratorIndex == -1) {
				spliteratorIndex = i;
				continue;
				
			}
		
			return std::pair<const char*, const char*>("", "");
		}
	}
	
	const char* s1 = nullptr;
	if (spliteratorIndex == 0)
		s1 = substring("0", 0, 0);
	else
		s1 = substring(string, 0, spliteratorIndex - 1);

	return std::pair<const char*, const char*>(
		s1, 
		substring(string, spliteratorIndex + 1, size - 1)
	);
}