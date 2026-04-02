#include <iostream>
using namespace std;

class Base{
	public:
		int b;
		virtual void start(){
			cout<<"base-starting"<<endl;
		}
		virtual void end(){
			cout<<"base-end"<<endl;
		}
		Base():b(10){}//initializor list 效率更高
};
class Derived:public Base{
	public:
		int d;
		void start(){
			cout<<"derived-starting"<<endl;
		}
		Derived():Base(),d(20){}//initializor list同时初始化b=10 d=20
};

void f1(){
	Base b;
	Derived d;
	Base *bptr[2];
	bptr[0]=&b;
	bptr[0]->start(); //调用base的start函数
	bptr[0]->end(); //调用base的end函数
	cout<<"Base的变量b是:   "<<bptr[0]->b<<endl;
	cout<<endl;
	cout<<endl;
	bptr[1]=&d;
	bptr[1]->start(); //调用derived的start函数
	bptr[1]->end(); //继承Base的end函数
	cout<<"Derived的变量b是:   "<<bptr[1]->b<<endl;
	// cout<<"Derived的变量d是:   "<<bptr[1]->d<<endl; invalid syntax
	cout<<"Derived的变量d是:   "<<d.d<<endl;//只能通过对象的atribute来调用d变量
	//Base 指针只能指向b的成员变量和虚函数 对于继承对象d的成员变量不能调用
	
}
int main(){
	f1();
	return 0;
}

/*
1. 初始化列表(Initializer List)：Base():b(10){} 和 Derived():Base(),d(20){} 高效初始化

2. 虚函数多态：基类指针bptr[1]指向派生类对象d时，start()调用派生类版本，end()调用基类版本（未重写）

3. 基类指针限制：bptr[1]只能访问Base的成员(b和虚函数)，无法直接访问Derived的成员d

4. 访问派生类成员：需通过派生类对象或派生类指针，如d.d
*/

