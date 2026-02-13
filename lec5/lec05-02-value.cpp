#include <iostream>
using namespace std;

void f(int y) {
	y = 10;
}

int main() {
	int y = 0;

    f(y);

	cout << "y from main() is: " << y << endl;

	return 0;
}
