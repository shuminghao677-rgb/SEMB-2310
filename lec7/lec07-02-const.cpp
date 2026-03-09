#include <iostream>
using namespace std;

int main() {
	//知识点1：普通变量声明和赋值规则
	int num1 = 100;
	num1=200;
	cout<<"num1="<<num1<<endl;

	//知识点2：const声明同时初始化常量 不可以被修改被重新赋值
	const int num2=100;
	// num2=300; //! 这里会报错 因为 const声明的变量不可以被修改
	cout<<"num2="<<num2<<endl;
	
	//知识点3：const使用规则
	int tmp=100;
	const int num3=tmp;
	cout<<"num3="<<num3<<endl;

	// const int num4;
	// num4=100; //! 这里会报错 因为const的常量变量必须在声明阶段就初始化赋值
	// cout<<"num4="<<num4<<endl;
    return 0;
}

/* 
1.const就是“只读”的意思，初始化后不能改，编译时会检查谁想改就报错

2.const变量必须一开始就给值，不能先声明后赋值

3.const分两种：编译期就知道值的（如const int a=100）可以做数组长度和switch case；运行时才知道值的（如用户输入、计算得到）不能做数组长度和switch case，但都不能修改
 */