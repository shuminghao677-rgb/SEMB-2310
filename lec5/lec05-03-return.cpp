#include <iostream>
using namespace std;

void f1() {
	cout << "f1 - line 1" << endl;
	cout << "f1 - line 2" << endl;
}

void f2() {
	cout << "f2 - line 1" << endl;
	cout << "f2 - line 2" << endl;
}

int main() {
	f1();
	f2();
	return 0;
}
