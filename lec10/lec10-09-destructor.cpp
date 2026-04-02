#include <iostream>
using namespace std;

class Machine{
	public:
		Machine(){
			cout<<"构建Machine对象"<<endl;
		}
		virtual ~Machine(){
			cout<<"析构Machine对象"<<endl;
		}
};
class Car:public Machine{
	public:
		int *cptr;
		Car(){
			cptr=new int;
			cout<<"构建子对象Car"<<endl;
		}
		~Car(){
			if(cptr){
				delete cptr;
				cptr=nullptr;
				cout<<"析构子对象Car"<<endl;
			}
		}
};

void f1(){ //在heap上分配内存 手动销毁 需要delete指针
	Machine *mptr=new Car;
	delete mptr;
	mptr=nullptr;
}

void f2(){//在stack上分配内存 结束自动销毁 不需要delete指针
	Car c;
	Machine *mptr;
	mptr=&c;
}

int main(){
	cout<<"====f1()调用===="<<endl;
	f1();
	cout<<endl;
	cout<<"====f1()调用===="<<endl;
	f2();
	return 0;
}

/*
1. 堆(Heap)：f1()中用new Car在堆上分配内存，必须手动delete释放

2. 栈(Stack)：f2()中用Car c在栈上分配内存，离开作用域自动释放

3. 虚析构：基类析构声明为virtual，确保delete基类指针时调用派生类析构

4. f1()执行：构建Machine → 构建Car → 析构Car(释放cptr) → 析构Machine

5. f2()执行：构建Machine → 构建Car → 函数结束自动析构Car → 析构Machine
*/


/*
1. 构造函数不能是虚函数：构造时vtable未建立，类型已确定

2. 析构函数必须是虚函数：delete基类指针时，确保调用派生类析构

3. 成员函数可以是虚函数：实现多态，运行时决定调用哪个版本

4. 虚函数表(vtable)：在构造函数执行完成后建立

5. 多态三要素：继承 + 虚函数 + 基类指针/引用指向派生类对象
*/