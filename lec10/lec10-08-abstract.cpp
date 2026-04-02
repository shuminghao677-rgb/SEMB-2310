#include <iostream>
using namespace std;

class Machine{
	public:
		virtual void start()=0;
};

class Car:public Machine{
	public:
};

class Bus:public Car{
	public:
		void start(){
			cout<<"busing"<<endl;
		}
};

void f1(){
	Bus b;
	Machine *mptr = &b;

	//两种方式打印 busing
	b.start();
	mptr->start();
}

int main(){
	f1();
	return 0;
}


/*
1. 纯虚函数：virtual void start() = 0，包含纯虚函数的类是抽象类，不能实例化

2. 派生类如果不重写纯虚函数，则派生类也是抽象类

3. 派生类重写所有纯虚函数后，才成为具体类，可以创建对象

4. 继承链传递：Machine(抽象) → Car(抽象) → Bus(具体)

5. 多态(Polymorphism)：基类指针指向派生类对象，通过指针调用虚函数，运行时决定调用哪个版本
*/