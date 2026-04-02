#include <iostream>
using namespace std;

class Machine{
	public:
		virtual void start()=0;
};
class Car:public Machine{
	public:
		virtual void start(){
			cout<<"driving"<<endl;
		}
};

void f1(){
	Car c;
	// Machine m; 此时是纯虚函数 virtual void start()=0; 不能建立对象
	Machine *mptr;
	mptr=&c;
	mptr->start();
	// mptr=&m;
	// mptr->start();
}
int main(){
	f1();
	return 0;
}


/*
1. 纯虚函数：virtual void start() = 0; 没有函数体，只有声明

2. 抽象类：包含纯虚函数的类称为抽象类，不能实例化对象

3. 派生类必须重写：Car必须实现start()，否则也是抽象类

4. 多态使用：可以用基类指针指向派生类对象，通过指针调用派生类版本

5. 注释说明：Machine m; 被注释，因为抽象类不能创建对象
*/