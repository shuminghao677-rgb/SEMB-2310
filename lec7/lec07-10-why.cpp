#include <iostream>
using namespace std;

int global=[](){
	cout<<"只有在main函数执行前才知道global全局变量的初始化值"<<endl;
	return 100;
}();
//和 int global =100；区别是这个是编译的时候就知道取值是100

void funct(){
	cout<<"main程序开始"<<endl;
}

int main() {
	funct();
	cout<<"全局变量global的取值是"<<endl;
	return 0;
}


/* 
输出结果是：
只有在main函数执行前才知道global全局变量的初始化值
main程序开始
全局变量global的取值是 
*/
//todo 说明初始化是在main函数马上开始之前进行的


/* 
1.int global=100：编译时就确定值，直接在.data段分配

2.int global=[](){...}()：main前才执行函数确定值，这叫动态初始化

3.执行顺序：全局动态初始化 → main函数开始 → 其他代码

4.输出结果证明：global初始化代码在main前执行，比funct()调用还早
*/
