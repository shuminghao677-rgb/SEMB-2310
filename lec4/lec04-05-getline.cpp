#include <iostream>
using namespace std;
void printStates();




int main() {
	char s[5];

	while(1) {
        

		cout << "\"" << s << "\"" << endl;
		cout << endl;
	}

	return 0;
}










































































void printStates() {
	cout << "failbit: " << cin.fail() << endl;
	cout << "eofbit: " << cin.eof() << endl;
	cout << "badbit: " << cin.bad() << endl;
	cout << "goodbit: " << cin.good() << endl;
	cout << endl;
}
