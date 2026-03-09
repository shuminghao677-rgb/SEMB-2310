#include <iostream>
using namespace std;


int main() {
	//知识点1：const 引用变量绑定普通变量
	int n=100;
	cout<<"n="<<n<<endl;
	const int &ref=n;
	n=300;
	cout<<"n="<<n<<endl;
	cout<<"ref="<<ref<<endl;
	cout<<endl;
	cout<<endl;
	/* ref=400;
	cout<<"n="<<n<<endl;
	cout<<"ref="<<ref<<endl;
	会报错
	 */

	 //知识点2：const 引用变量绑定const变量
	const int m=100;
	const int &ref1=m;
	cout<<"m="<<m<<endl;
	cout<<"ref1="<<ref1<<endl;
	/* 
	m=200; 因为是const变量不能更改
	会报错
	 */
	return 0;
}


/* 
1.const引用绑定普通变量：原变量可改，const引用跟着变，但不能通过const引用修改

2.const引用绑定const变量：原变量和引用都不可修改，两者都是只读

3.const引用提供“只读访问权限”：能看不能改，但原变量如果是普通变量，它自己可以改
*/