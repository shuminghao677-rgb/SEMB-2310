#include <iostream>
using namespace std;

class Base {
	public:
		Base():x(1), y(2), z(3) {} //参数构建函数 其中x是public变量 y是protected变量 z是private变量
	public:
  		int x;
	protected:
  		int y;
	private:
  		int z;
};

class A :public Base { //A的public继承 x还是public变量 y还是protected变量 z还是private变量
	public:
		void func();
};

void A::func() { //还是class A的member function 属于类外定义 protected变量依然可以访问
	x = 10;//只能访问 x pulic变量 和 y protected变量
	y = 20;
	/* z = 30; z是Base的 private 变量不可访问*/ 
}


class B :protected Base { //对 class Base进行protected继承
	public:
		void func();
};
void B::func() {
	x = 10; //x和y都是Base的 protected变量可以访问
	y = 20;
	//  z = 30;	z还是Base的 private变量不可以访问 
}


class C :private Base { //对 class Base进行private继承
	public:
		void func();
};
void C::func() {
	x = 10; //此时x 和 y都是C里的private变量只能内部访问 在外部 都不能通过 C c； c.x c.y 来访问了
	y = 20;
	// z = 30;	
}

int main() {

	A a;
	cout << a.x << endl;
	// cout << a.y << endl; //y是A的protected变量 不能外部访问 可以被继承
	// cout << a.z << endl; //z是Base的private变量 A都不能继承

	cout << endl;

	B b;
	// cout << b.x << endl;//x是B的protected变量 不能外部访问 可以被继承
	// cout << b.y << endl;//y是B的protected变量 不能外部访问 可以被继承
	// cout << b.z << endl;//z是Base的private变量 B都不能继承

	C c;
	// cout << c.x << endl;//x是C的private变量 不能外部访问 不能被继承
	// cout << c.y << endl;//y是C的private变量 不能外部访问 不能被继承
	// cout << c.z << endl;//z是Base的private变量 C都不能继承

	return 0;
}



/* 
1.包容度等级：public > protected > private（从高到低）

2.继承规则：继承方式作为“筛子”，基类权限≥筛子的降级到筛子等级，＜筛子的保持原样

3.public继承（筛子=public）：基类public→public，基类protected→protected，基类private→不可见

4.protected继承（筛子=protected）：基类public→protected，基类protected→protected，基类private→不可见

5.private继承（筛子=private）：基类public→private，基类protected→private，基类private→不可见

6.public权限：可外部访问，可被继承

7.protected权限：不可外部访问，可被继承

8.private权限：不可外部访问，不可被继承
*/