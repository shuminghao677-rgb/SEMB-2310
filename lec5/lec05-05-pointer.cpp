#include <iostream>
using namespace std;

//这个是指针传参 helper 里面的形参是指针 最后返回值都是通过指针返回 *p
char changeChar(char *p){
	*p='H';
	return *p;
}

int main(){ //主函数call 调用函数的时候对原来的值 &original作为参数
	char original='A';
	char newChar=changeChar(&original);
	cout<<"The changed character is: "<<newChar<<endl;
	return 0;
}

// //引用传参
// char changeChar(char &Char){
// 	Char='H';
// 	return Char;
// }
// int main(){
// 	char Original='A';
// 	char Changed=changeChar(Original);
// 	cout<<"The changed character is "<<Changed<<endl;
// 	return 0;
// }