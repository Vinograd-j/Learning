#include <iostream>

using namespace std;

void readPointer(int*);
void readReference(int&);



int mAin() {

	int n1, n2;

	readPointer(&n1);
	readReference(n2);

	cout << n1 << endl;
	cout << n2 << endl;

	return 0;
}

void readPointer(int* number){
	cin >> *number;
}


void readReference(int& number) {
	int* p = &number;
	cin >> number;
}