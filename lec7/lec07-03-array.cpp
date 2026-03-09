#include <iostream>
using namespace std;

int main() {

	//知识点1：初始化数组
	const int length=5;
	int a[length]={0};
	//此时的数组就是a[5]={0,0,0,0,0}
	for(int i=0;i<5;i++){
		cout<<"a["<<i<<"]="<<a[i]<<endl;
	}

	//知识点2：指针数组
	int val1=100,val2=200,val3=300,val4=400,val5=500;
	int *ptrs[5]={&val1,&val2,&val3,&val4,&val5}; //这是声明一个整数数组指针类型的变量 后面&是对值取地址
	for (int i=0;i<5;i++){
		cout<<"ptrs["<<i<<"]="<<*ptrs[i]<<endl; // *p 就是对一个指针取值 &val就是对一个值取指针地址
	}

	//1.
	int b[5]={0,0,0};
	for(int i=0;i<5;i++){
		cout<<"b["<<i<<"]="<<b[i]<<endl;
	}//会自动补0
	

	//2. 4. 5.
	int *ptrs2[5]; //这里的* 是只声明的是指针变量 之后的指针数组就是 ptrs2 [5]是指针数组的长度
	int c[5]={1,2,3,4,5};
	for(int i=0;i<5;i++){
		ptrs2[i]=&c[i];//这里是用&对值取地址赋值 [i]是索引
		cout<<"*ptrs2["<<i<<"]="<<*ptrs2[i]<<endl;
	}

	//3.
	cout<<"打印c数组的第一个元素的地址"<<c<<endl;
	*c=11; //对c数组的第一个元素重新进行复制
	for(int i=0;i<5;i++){
		cout<<"c["<<i<<"]="<<c[i]<<endl;
	}
	return 0;
}



/* 
1.数组初始化时若元素个数不够，剩下的自动补0

2.指针数组：int *ptrs[5]表示ptrs是数组，长度5，每个元素都是int*指针

3.数组名是“指向第一个元素的常量指针”（a等价于&a[0]），但不能给数组名赋值（a=&val1报错）

4.声明时的*表示“这是指针”，使用时的*表示“取值”（解引用）

5.区分定义时的[长度]和使用时的[索引]：int arr[5]定义长度5，arr[0]访问第一个元素
*/





