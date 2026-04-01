#include <iostream>
using namespace std;

class Machine {
    public:
    virtual void start() {
        cout << "starting" << endl;
    }
};

class Car :public Machine {
};

class Truck :public Car {
};

class Bus :public Car {
};


int main() {

	return 0;
}

