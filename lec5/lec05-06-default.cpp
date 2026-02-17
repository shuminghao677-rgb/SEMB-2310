#include <iostream>
using namespace std;

void f(int a, int b, int c=0) {
	cout << "a is " << a << endl;
	cout << "b is " << b << endl;
	cout << "c is " << c << endl;
}

int main() {
	int a=1, b=2, c=3;
	f(a,b);//这里调用函数的时候没有c c就直接去default value 0
	cout << endl;
	return 0;
}
