#include <iostream>
using namespace std;

class Machine{
	public:
		virtual void start(){
			cout<<"virtual 父对象 start 函数"<<endl;
		}
		virtual void end(){
			cout<<"virtual 父对象 end 函数"<<endl;
		}
		void PlaySound(){
			cout<<"非virtual 父对象 PlaySound 函数"<<endl;
		}
	};
class Car:public Machine{
	public:
		void start(){
			cout<<"overloading 子对象 start 函数"<<endl;
		}
		void end(){
			cout<<"overloading 子对象 end 函数"<<endl;
		}
		void PlaySound(){
			cout<<"overloading 子对象 PlaySound 函数"<<endl;
		}
};

void f() {
	Car c;
	Machine *mptr=&c;
	mptr->start();//因为是 virtual 函数 调用的是父对象start函数
	cout<<endl;
	mptr->end();//因为是 virtual 函数 调用的是父对象end函数
	cout<<endl;
	mptr->PlaySound();//因为是 virtual 函数 调用的是父对象PlaySound函数
}

int main() {
	f();
	return 0;
}


/*
1. 虚函数(virtual)：start()和end()是虚函数，支持多态

2. 非虚函数：PlaySound()不是虚函数，不支持多态

3. f()中mptr指向Car对象，但类型是Machine*

4. 虚函数调用：根据实际对象(Car)决定 → 调用Car::start()和Car::end()

5. 非虚函数调用：根据指针类型(Machine*)决定 → 调用Machine::PlaySound()

6. 输出结果：子对象的start和end，父对象的PlaySound
*/