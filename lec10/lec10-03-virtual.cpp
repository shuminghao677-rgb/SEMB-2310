#include <iostream>
using namespace std;

class Machine {
	public:
		virtual void start() { 
			cout << "base starting..." << endl; 
		}
};

class Car :public Machine {
	public:
		void start() {
			cout << "driving..." << endl;	
		}
};

class Drone :public Machine {
	public:
		void start() {
			cout << "flying..." << endl;	
		}
};

class Boat :public Machine {
	public:
		void start() {
			cout << "sailing..." << endl;	
		}
};


void f1() {
	Car c;
	Machine *mptr=&c;
	mptr->start();//指向的是 car的start函数
	Drone d;
	mptr=&d;
	mptr->start();//指向的是 drone的start函数
	Boat b;
	mptr=&b;
	mptr->start();//指向的是 boat的start函数
}

void f2(Machine *mptr) {
	mptr->start();//根据参数的引用对象决定调用的是哪个子对象start函数
}

int main() {
	Car cc;
	f1();
	cout<<endl;
	f2(&cc); //参数对象是Car所以调用car的start函数
	return 0;
}

/*
1. 虚函数(virtual)：基类Machine的start()声明为virtual，实现多态

2. 动态绑定：基类指针指向派生类对象时，调用的是实际对象的start()

3. f1()演示：同一个基类指针mptr先后指向Car、Drone、Boat，调用各自不同的start()

4. f2()演示：函数参数为基类指针，传入不同派生类对象地址，根据实际对象调用对应函数

5. 多态核心：基类指针/引用 + virtual函数 + 派生类对象 → 运行时决定调用哪个版本
*/