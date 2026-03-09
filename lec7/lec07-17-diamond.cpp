#include <iostream>
using namespace std;

class Person {
	public:
  		int age;
		Person(){
			age=0;
		}
};

class Mother :public Person {
	public:
		Mother(){
			age=50;
		}
};

class Father :public Person {
	public:
		Father(){
			age=51;
		}
};

class Child :public Mother,public Father{
	public:
		Child(){
		Mother::age=20;
		Father::age=21;
	}
};


int main() {
	Child c;
	cout<<endl;
	cout<<"Father和Father继承的Person的age值是：  "<<c.Father::age<<endl;
	cout<<endl;
	cout<<"Mother和Mother继承的Person的age值是：  "<<c.Mother::age<<endl;
	cout<<endl;
	cout<<"Person的大小"<<sizeof(Person)<<endl;
	cout<<endl;
	cout<<"Mother的大小"<<sizeof(Mother)<<endl;
	cout<<endl;
	cout<<"Father的大小"<<sizeof(Father)<<endl;
	cout<<endl;
	cout<<"Child的大小"<<sizeof(Child)<<endl;
	cout<<endl;
	return 0;
}


/* 
1.普通继承：每个派生类包含基类的所有成员变量

2.菱形继承：Child同时继承Mother和Father，而两者又继承Person

3.内存结果：Child中有两个独立的Person子对象 → 两个age变量

4.大小计算：Person=4字节，Mother=4字节，Father=4字节，Child=8字节（4+4）

5.验证：sizeof(Child)等于两个基类大小之和，证明有两个age副本

6.二义性根源：两个age导致直接访问c.age报错，必须用c.Mother::age或c.Father::age区分
*/