#include <iostream>
using namespace std;

class Person{
	public:
		Person(){
			age=0;
		}
		int age;
};

class Mother :virtual public Person{ //和 Father继承的共享一个Person
	public:
		Mother(){
			age=20;
		}
};

class Father :virtual public Person{ //和 Mother继承的共享一个Person
	public:
		Father(){
			age=21;
		}
};

class Child :public Mother,public Father{ //所有从Father 和Mother 那里继承来的实际是一个Person
	public:
		Child(){
			age=30; //所以不需要作用域 直接age=30 不需要 Mother::age=30 Father::age=30
		}
};

int main(){
	Child c;
	//所以 最后 Child Father Mother 指向的都是一个Person 所以都是30
	cout<<"Child 的年龄是"<<c.age<<endl;
	cout<<"Person 的年龄是"<<c.Person::age<<endl;
	cout<<"Mother 的年龄是"<<c.Mother::age<<endl;
	cout<<"Father 的年龄是"<<c.Father::age<<endl;
	return 0;
}

/* 
1.虚继承（virtual inheritance）：解决菱形继承问题，让Person只保留一份副本

2.共享内存：Mother和Father虚继承Person，Child中只有一个共享的Person子对象

3.构造顺序：先构造虚基类Person（age=0），再构造Mother（age=20），再构造Father（age=21），最后Child（age=30）

4.最终覆盖：最后一次修改（Child的30）覆盖之前所有值，所有路径看到的都是30

5.访问简化：因为只有一个age，可以直接c.age访问，不需要作用域限定

6.输出验证：所有输出都是30，证明指向同一个Person
*/