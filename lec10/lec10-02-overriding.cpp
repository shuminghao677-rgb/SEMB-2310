#include <iostream>
using namespace std;
class Machine{
	public:
		void start(){
			cout<<"父对象函数 starting"<<endl;
		}
};
class Car:public Machine{
	public:
		void start(){
			cout<<"子对象Car函数 driving"<<endl;
		}
};

class Boat:public Machine{
	public:
		void start(){
			cout<<"子对象Boat函数 boating"<<endl;
		}
};

void f1() {
	Car c;
	Car *cptr=&c;
	c.start();
	cptr->start();
	cptr->Machine::start();
	cout<<"f1函数演示子对象的start和子对象指针指向父对象的start函数"<<endl;
}

void f2() {
	Car c;
	Machine *mptr=&c;
	c.start();
	mptr->start();
	cout<<"f2函数演示子对象的start和父指针指向子对象边缘但触发父对象的start函数"<<endl;
}

int main() {
	f1();
	cout<<endl;
	f2();
	return 0;
}

/*
1. 继承关系：Car和Boat公有继承Machine

2. 函数隐藏：派生类start()隐藏基类start()（非虚函数）

3. 子类对象调用：c.start() 和 Car*指针调用 cptr->start() 都执行派生类版本

4. 强制调用基类：cptr->Machine::start() 用作用域限定符执行基类版本

5. 基类指针：Machine*指向派生类对象时，调用基类版本（静态绑定，编译时决定）
*/