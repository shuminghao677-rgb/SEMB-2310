#include <iostream>
using namespace std;

int main() {

	int x;
	cout << "Enter x: ";
	cin >> x;
	switch(x){
		case 1:
		    cout<<"the input is one";
		    break;//不需要 braces 但是需要每个 case 下面要break
		case 2:
		    cout<<"the input is two";
			break;
		default:
		    cout<<"the input is greater than two";
		    break;
	}
	// switch case 只能做整数值的判断
	return 0;
}
