#include <iostream>
using namespace std;

class Base1{
	public:
		Base1(){
			x=1;
		}
		int x;
		void show1(){
			cout<<"Base1'x is: "<<x<<endl;
		}
};

class Base2{
	public:
		Base2(){
			x=2;
		}
		int x;
		void show2(){
			cout<<"Base2'x is: "<<x<<endl;
		}
};

class Child : public Base1,public Base2{ // 多重继承
	public:
		Child(){
			Base1::x=10; // 修改从Base1继承来的x
			Base2::x=20; // 修改从Base2继承来的x
			// x = 10;  ❌ 歧义错误！不知道是哪个x
		}
};

int main() {
	Child c;
	cout<<c.Base1::x<<endl;
	cout<<c.Base2::x<<endl;
	c.Base1::show1();
	c.Base2::show2();
	return 0;
}


/* 
1.多继承语法：class Child : public Base1, public Base2 {};

2.核心问题：ambiguity（多个基类有同名成员，如两个x）

3.直接访问歧义：在子类中写x编译器不知道是哪个基类的x → ambiguity error

4.解决方法：用Base1::x或Base2::x明确指定访问哪个基类的成员

5.注意事项：多继承增加复杂度，谨慎使用，优先考虑composition
*/