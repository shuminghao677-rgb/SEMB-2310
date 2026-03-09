#include <iostream>
using namespace std;

class Base {
	public:
  		Base(){
			x=1; //还是一个默认构造函数因为没有括号内没有参数 函数内给x赋值
		} 
  		void f(){
			cout << "base-1" << endl;//无参数的member function
			cout << x << endl;
		} 
  		void f(int z) {
			cout << "base-2,成员函数的参数是：  "<<z<< endl; //有参数的member function
		} 
		int x; //声明变量x
};

class Child :public Base{
	public:
		Child(){
			x=2; //和Base class相同的变量名 x写在默认构建函数的函数里
		 }
		void f(){
			cout << "child-1" << endl;//无参数的member function
		}
		void f(int z) {
			cout << "child-2,成员函数的参数是：  "<<z<< endl; //有参数的member function
		} 
};

int main() {
	Child c;
	cout<<"Child里的x变量是：  "<<c.x<<endl;
	cout<<"Base里的x变量是：  "<<c.Base::x<<endl; //这里因为是继承Base里的x 就和 引用里ref变了 n也跟着变了 所以无论是Child里的x还是Base里的x都是2
	c.f();
	c.f(2);
	c.Base::f();
	c.Base::f(1);
	
	return 0;
}


/* 
1.构造顺序：先Base构造函数设x=1，再Child构造函数设x=2，最终x=2

2.只有一个x变量（Child继承Base的x，没有自己声明新的），所以c.x和c.Base::x是同一个变量

3.函数隐藏：Child的f()和f(int)隐藏了Base的同名函数，直接调用c.f()走Child版本

4.通过Base::可以调用被隐藏的基类函数：c.Base::f()调用基类无参版，c.Base::f(1)调用基类有参版

5.输出结果：c.x=2，c.Base::x=2，child-1，child-2，base-1输出2，base-2
*/