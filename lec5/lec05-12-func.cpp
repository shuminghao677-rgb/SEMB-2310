#include <iostream>
using namespace std;

void func(int n) {

	// statements

	func(n-1);

	// statements

}

int main() {

	int n = 10;

	func(n);

	return 0;
}
