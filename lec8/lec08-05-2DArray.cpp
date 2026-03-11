#include <iostream>
using namespace std;
void f1(char b[][6],int row1){
	for(int i=0;i<row1;i++){
		cout<<b[i]<<endl;
	}
}

void f2(char (*p)[6],int row2){
	for(int i=0;i<row2;i++){ //相当于循环六次
		cout<<*(p++)<<endl; //对p头元素地址取值也就是整个字符串 ++不是指向下一个元素 而是下一行
		//因为声明的时候是 char (*p)[6]
	}
}




int main() {
	int a[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};	
	int *p = a[0];


	return 0;
}
