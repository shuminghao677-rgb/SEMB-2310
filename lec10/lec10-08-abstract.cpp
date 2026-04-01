#include <iostream>
using namespace std;

class Machine {
	public:
		virtual void start() = 0; 
};

class Car :public Machine {
	public:
};


void f() {

}

int main() {
	f();
	return 0;
}
