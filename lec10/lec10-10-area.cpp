#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.1415;

class Shape {
    public:
        virtual double area() = 0;
        virtual void print() = 0;
};

class Circle :public Shape {
    public:
    private:
        double r;
};

class Rectangle :public Shape {
    public:
    private:
        double wide, len;
};

class Triangle :public Shape {
    public:
    private:
        double a, b, c;
};

int main() {
    
    int n;
    cout << "Input the number of shapes: " << endl;
    cin >> n;
	

    char type;
    double a, b, c;
    
	for(int i = 0; i < n; i++) {
		cout << "~~~~~~~~" << i+1 << "~~~~~~~~" << endl;
		cout << "c: circle" << endl;
		cout << "r: rectangle" << endl;
		cout << "t: triangle" << endl;
		cout << "~~~~~~~~~~~~~~~~~" << endl;

        cin >> type;
        switch (type){
            case 'c':{
				cout << "Radius: ";
                cin >> a;

                break;
            }
            case 'r':{
				cout << "Two sides: ";
                cin >> a >> b;

                break;
            }
            default:{
				cout << "Three sides: ";
                cin >> a >> b >> c;
				
            }
        }
    }
    for(int i = 0; i < n; i++) {
		cout << endl;
    }


	return 0;
}

