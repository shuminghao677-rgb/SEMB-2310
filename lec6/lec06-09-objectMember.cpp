#include <iostream>
using namespace std;

class AClass {
public:
	AClass() 	{ cout << "A-Construction" << endl;}
	~AClass() 	{ cout << "A-Destruction" << endl;}
};

class BClass {
public:
	BClass() 	{ cout << "B-Construction" << endl;}
	~BClass() 	{ cout << "B-Destruction" << endl;}

	AClass a;
};


int main() {

	BClass b;

	return 0;
}
