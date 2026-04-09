#include <iostream>
using namespace std;

template <typename T>
T myadd(T a,T b){
	return a+b;
}

int main(){

	cout<<"This is the sample of emplict specification"<<endl;
	cout<<myadd<int>(1,2)<<endl;
	cout<<endl;

	cout<<"This is the sample of implict conversation"<<endl;
	cout<<myadd<int>(1,'a')<<endl;
	cout<<endl;

	cout<<"This is the sample of type deduction"<<endl;
	cout<<myadd(1.11,2.22)<<endl;
	cout<<endl;

	return 0;
}

/*
1. 显式指定(Explicit Specification)：myadd<int>(1,2) 明确告诉编译器 T=int

2. 隐式转换(Implicit Conversion)：myadd<int>(1,'a') 先指定 T=int，char('a')自动转为int(97)

3. 类型推导(Type Deduction)：myadd(1.11,2.22) 编译器自动推导 T=double

4. 模板参数必须一致：自动推导时两个参数类型必须相同，否则编译错误
*/

