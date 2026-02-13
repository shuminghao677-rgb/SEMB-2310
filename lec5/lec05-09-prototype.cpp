#include <iostream>
using namespace std;
//通常会在开头进行使用的函数声明
#include "lib.h" //在lib.h里有函数声明 在lib.cpp中有函数定义
#include <string>

int main() {
	int n=findMax(3,5); //调用函数 给返回的结果赋值给n
	cout<<n<<endl; //打印n
	greet("Tom"); //因为是一个直接输出函数 调用就有结果
	return 0;
}


