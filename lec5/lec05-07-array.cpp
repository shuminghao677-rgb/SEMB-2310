#include <iostream>
using namespace std;

void f(int a[]) {
	a[0] = 10;
}

int main() {
	int a[3] = {1,2,5};

	cout << "a[0] from main() is : " << a[0] << endl;
	
	return 0;
}
