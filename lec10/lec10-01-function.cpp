#include <iostream>
using namespace std;

class A {
	public:
		void func(){
			cout<<"成员无参函数"<<endl;
		}
		void func(int x){
			cout<<"成员整数参函数，整数是：  "<<x<<endl;
		}
		void func(double x){
			cout<<"成员double参函数， double是：  "<<x<<endl;
		}
};
void func(){
	cout<<"全局无参函数"<<endl;
}

int main() {
	A a;
	a.func();
	a.func(5);
	a.func(3.14);
	func();
	return 0;
}

/*
1. 重载：同一作用域内函数名相同、参数不同（个数/类型）

2. 类内重载：func()、func(int)、func(double) 三个重载版本

3. 全局函数：func() 与类内重载不同作用域，不算重载

4. 调用区分：成员函数用对象调用(a.func())，全局函数直接调用(func())
*/
