#include <iostream>
using namespace std;

//todo 数组引用传参
// void f(int a[]) {//这里的空括号说明不知道size的长度
// 	a[0] = 10; //对于数组的引用传参 不需要 &
// }

// int main() {
// 	int a[3] = {1,2,5};//因为这里是第一次声明 所以就是a[3]表示数组的长度 后面就是数组的内容
// 	f(a);//call 数组的函数的时候 里面只有数组的名字
// 	cout << "a[0] from main() is : " << a[0] << endl;
	
// 	return 0;
// }

//todo 数组指针传参
void changeElement(int *p){
	*(p+1)=2*(*(p+1)); //这里是对指针所指数组的第二个元素进行处理
}

int main(){
	int a[3]={3,4,5};
	changeElement(a); //因为本身数组指的就是第一个元素的地址 所以数组的指针传参 调用不需要&
	cout<<"the changed second element is "<<a[1]<<endl;
	return 0;
}

//总结 对于数组传参
//* 首先引用传参 helper函数的形参 不需要&
//* 对于指针传参 *(p+1)后一位的值 以及在调用的时候参数部分不需要 & 本身数组a就是第一个元素的地址