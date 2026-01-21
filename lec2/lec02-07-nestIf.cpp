#include <iostream>
using namespace std;

int main() {
	int a, b;
	cout << "Enter a and b:" << endl;
	cin >> a >> b;

	if(a==1)
		if(b==2)
			cout << "***" << endl;
    	else
			cout << "###" << endl;

	return 0;
}
