#include <iostream>
#include <fstream>

void maidgfn() {

	auto out = std::ofstream("text.txt");

	auto in = std::ifstream("text.txt");

	if (!out.is_open()) {
		throw "Can`t open";
	}

	out << "Hello world";


	size_t count = 0;

	while (!in.eof()) {

		std::string s;
		in >> s;
		count++;
	}

	std::cout << count;

	out.close();
	in.close();

}
