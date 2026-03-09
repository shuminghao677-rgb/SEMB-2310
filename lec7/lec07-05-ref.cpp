#include <iostream>
using namespace std;

int main() {
	//知识点1：声明引用变量
	int n = 100;
	int &ref = n;
	cout<<"ref="<<ref<<endl;
	cout<<endl;
	//知识点2：修改引用变量
	n=300;
	cout<<"ref="<<ref<<endl;
	cout<<endl;
	//知识点3：引用变量不可以重复绑定
	int m=400;
	ref=m;
	cout<<"ref="<<ref<<endl; //所以这里不是让ref绑m 而是用m的值 对 ref和n重新赋值
	cout<<"n="<<n<<endl;

	return 0;
}


/* 
1.引用定义格式：int &ref = n，必须初始化，不能绑字面量（int &ref = 100是错的）

2.引用和原变量共用同一块内存，改引用就是改原变量

3.引用一旦绑定就不能改绑，ref = m不是重新绑定，而是把m的值赋给ref（也就是赋给n）
*/
