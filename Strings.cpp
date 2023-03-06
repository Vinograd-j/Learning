#include <iostream>


size_t findAllLatinLowerCase(const std::string& string);

std::string changeUpperToLower(const std::string& string);

size_t findPalindromes(const std::string* strings, size_t size);

bool isPalindrome(const std::string& string);

int calc(const std::string& string);


void maidfgn() {

    
	std::string strings[] = { "abba", "dfssdfa", "uiiu" };


	std::cout << calc("1+2-4+4");
}

size_t findAllLatinLowerCase(const std::string& string)
{
	
	size_t count = 0;

	for (size_t i = 0; i < string.length(); i++)
	{

		if (string[i] >= 'a' && string[i] <= 'z')
			count++;
	}

	return count;
}

std::string changeUpperToLower(const std::string& string)
{
	std::string changed(string);

	int delta = 'A' - 'a';

	for (size_t i = 0; i < string.length(); i++)
		if(string[i] >= 'A' && string[i] <= 'Z')
			changed[i] -= delta;

	return changed;
}

size_t findPalindromes(const std::string* strings, size_t size)
{
	
	size_t count = 0;

	for (size_t i = 0; i < size; i++)
		if (isPalindrome(*(strings + i)))
			count++;

	return count;
}

bool isPalindrome(const std::string& string) {

	for (size_t i = 0; i < string.size() / 2; i++)
		if (string[i] != string[string.size() - i - 1])
			return false;
	
	return true;

}

int calc(const std::string& string)
{

	bool expectDigit = true;
	
	int number = 0;

	char operation = '0';

	char lastSymbol = string[string.length() - 1];

	if (lastSymbol < '0' || lastSymbol > '9')
		throw "Symbol is`t a digit";


	for (auto c : string)
	{
		if (expectDigit) {

			if (c < '0' || c > '9')
				throw "Symbol is`t a digit";

			if(operation == '0')
				number = c - '0';
			else if (operation == '+')
				number += c - '0';
			else
				number -= c - '0';

		}
		else {
			if (c == '-' || c == '+')
				operation = c;
			else
			{
				throw "Operation didn`t find";
			}
			
		}

		expectDigit = !expectDigit;

	}

	return number;
}
