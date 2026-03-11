#include <iostream>
using namespace std;

const int N = 10;

int main() {
	int a[N] = {1,2,3,4,5,6,7,8,9,10};
	int sum = 0;


	// for循环方法1
	for(int i=0;i<N;i++){
		sum+=a[i];
	}
	cout << "First sum: " << sum << endl;


	// for循环方法2
	sum=0;
	for(int i=0;i<N;i++){
		sum+=*(a+i);
	}
	cout << "Second sum: " << sum << endl;


	// for循环方法3
	sum=0;
	int *p=a;
	for(int i=0;i<N;i++){
		sum+=*(p++);
	}
	cout << "Third sum: " << sum << endl;

    return 0;
}


/* 
1.数组名a是常量指针，指向第一个元素，不可修改

2.方法1：用下标a[i]访问数组元素，最直观

3.方法2：用指针算术*(a+i)访问，a是地址，+i移动i个元素

4.方法3：用移动指针*(p++)，p++先取当前值再自增，逐个遍历

5.三种方法本质相同，都是通过地址偏移访问数组元素
*/