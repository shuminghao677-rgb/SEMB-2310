#include <iostream>
using namespace std;

class Base {
  public:
	    virtual void start() {
			cout << "base-starting..." << endl;
		}
    	virtual void end() {
			cout << "base-end..." << endl;
		}
};

class Derived :public Base {
};


int main() {

	return 0;
}
