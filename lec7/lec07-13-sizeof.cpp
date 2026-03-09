#include <iostream>
using namespace std;

class Base {
	public:
  		int x; //int 四个字节 32位
		int static x_static; //静态变量也不占内存空间
	protected:
  		int y; //int 四个字节 32位
	private:
  		int z; //int 四个字节 32位
		void f1(){
			cout<<"func1"<<endl; //member function 和类的大小无关
		}
		void f2(){
			cout<<"func2"<<endl;
		}
};

class Empty{};


int main() {
	cout<<"Base类的大小:  "<<sizeof(Base)<<endl;
	cout<<"空类的大小:  "<<sizeof(Empty)<<endl;
	Base b;
	cout<<"Base类对象的大小:  "<<sizeof(b)<<endl;
	return 0;
}


/* 
1.类的大小由非静态成员变量决定：Base有x、y、z三个int（各4字节），共12字节

2.静态成员变量x_static存在静态区，所有对象共享，不占类大小

3.成员函数f1()、f2()存在代码区，不占类对象内存

4.空类占1字节：编译器给占位符，保证每个对象有唯一地址

5.类和类对象大小相同：sizeof(Base)=sizeof(b)=12
*/
