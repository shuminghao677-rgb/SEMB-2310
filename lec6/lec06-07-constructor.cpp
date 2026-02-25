#include <iostream>
using namespace std;

class Circle {
	public:
        int getRadius() { return radius; }
		
	private:
		int radius;

};


int main() {
	
	Circle c;
	cout << "Radius is: " << c.getRadius() << endl;

	return 0;
}
