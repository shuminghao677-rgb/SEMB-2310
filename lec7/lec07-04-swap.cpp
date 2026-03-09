#include <iostream>
using namespace std;

void swap1(int &x,int&y){ //引用传参 作为helper function 参数int &x int &y xy是值
	int tmp;
	tmp=x;
	x=y;
	y=tmp;
}

void swap2(int *x,int *y){ //指针传参 参数的地方放的是地址
	int tmp;
	tmp=*x;
	*x=*y;
	*y=tmp;
}

int main() {
	int a=5, b=6;
	cout << "a is: " << a << endl;
	cout << "b is: " << b << endl;
	swap1(a,b);//调用 void swap函数
	cout << "a is: " << a << endl;
	cout << "b is: " << b << endl;
	swap2(&a,&b);
	cout << "a is: " << a << endl;
	cout << "b is: " << b << endl;
	return 0;
}


/* 
1.引用传参（int &x）：x是a的别名，直接操作原变量，调用时swap1(a,b)就行

2.指针传参（int *x）：x存的是a的地址，操作时要加*解引用，调用时要传&a

3.引用传参像在函数里直接用原变量，指针传参像拿着地址去找原变量

4.引用主要用于函数参数，指针用途更广但语法更复杂
*/
