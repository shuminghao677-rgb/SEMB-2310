#include <iostream>
using namespace std;

void showArray(int *p, int len) {
	for(int i=0; i<len; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}

int main() {

	int *p1=new int(100); //new的同时初始化
	cout<<"存入的整数100内存地址p1是：  "<<p1<<endl;
	delete p1;//释放内存 
	p1=nullptr;//防止 wilf ptr 

	int *p2=new int;//new后赋值
	*p2=100;
	cout<<"存入的整数100内存地址p2是：  "<<p2<<endl;
	delete p2;
	p2=nullptr;

	int len=5;//设置长度
	int *p3= new int[len]; //给数组头元素指针p3 分配内存 new int[len]带着长度
	for (int i=0;i<len;i++){//循环赋值 可以直接用 
		*(p3+i)=(i+1)*10; //p3既可以是第一个元素地址也可以是数组 所以也可以用p3[i]循环复制
	}

	cout<<"动态数组元素:  "<<endl;
	showArray(p3, len);//调用helper function 一个指针传参
	delete []p3;//释放数组内存 delete[]
	p3=nullptr;
	return 0;
}


/* 
1.new int(100)：分配堆内存并初始化值为100，用delete释放

2.new int：只分配不初始化，需手动赋值(*p=100)，同样用delete释放

3.new int[len]：分配数组，返回首元素地址，用delete[]释放

4.p3既是首元素地址，也可当数组名用，p3[i]和*(p3+i)等价

5.delete后置nullptr是好习惯，防止野指针(wild pointer)

6.showArray用指针传参，可接收动态数组或普通数组
*/ 




