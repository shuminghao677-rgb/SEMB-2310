#include <iostream>
using namespace std;

class Base{//基类
	public:
	//删除了构建默认函数 因为编译器会自己构建
		int x=10;
		void show(){
			cout<<"x set in Base is:  "<<x<<endl;
		}
};
class Child : public Base { //子类继承基类 class Child ： public Base{}
	public:
		int y=20;
		void show_all(){
			cout<<"y set in Child is:  "<<y<<"   x set in Base is:  "<<x<<endl; //可以同时用子类和基类的public 变量
		}
};

int main(){
	Child c; //创建子类对象 c 同时有了继承的Base
	c.show(); //调用继承来的函数
	c.show_all(); //调用子类自己的函数
	cout<<"直接打印x值"<<c.x<<endl;
	cout<<"直接打印y值"<<c.y<<endl; 
	return 0;
}

/* 
1.基类（父类）Base：定义了成员变量x和成员函数show()

2.子类Child公有继承Base：使用": public Base"语法，拥有Base的所有public成员

3.继承后：Child对象包含继承来的x和show()，加上自己的y和show_all()

4.访问权限：子类内部可以直接使用继承来的public成员（如x）

5.对象创建：Child c会调用编译器自动生成的默认构造函数

6.使用方式：通过子类对象可以调用基类函数c.show()和访问基类变量c.x
*/


/* 
1.子类继承基类后，可以直接访问基类的public成员（如x）和protected成员

2.子类不能直接访问基类的private成员（私有成员只有基类自己能访问）

3.protected介于中间：子类可访问，但类外部不能直接访问

4.这是C++的访问控制机制，用于封装和数据隐藏
*/