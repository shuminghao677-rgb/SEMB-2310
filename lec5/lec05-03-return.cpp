#include <iostream>
using namespace std;

int changeValue(int &y){
	y=10;
	return y;
}

int main(){ //main函数必须要 返回结果 不能是 void 所以这里 int main 返回return 0
	int x=0;
	x=changeValue(x); //因为前面helper函数是一个return 返回值的 所以这里可以直接=变量赋值
	cout<<"the twice of the changed value: "<< 2*x<<endl;
	return 0;
}