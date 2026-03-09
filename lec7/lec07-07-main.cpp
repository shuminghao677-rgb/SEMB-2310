#include <iostream>
using namespace std;

int main(int argc,char *argv[]){ //这里 *argv[]因为参数是 指针字符串组
	cout<<"参数个数："<<argc<<endl;
	cout<<"所有参数："<<endl;
	for(int i=0;i<argc;i++){ 
	//对于指针字符串组 argv[i]指向第i个字符串的第一个字符的地址 但是cout会一直打印到\0前也就是整个字符串
	//但如果是*argv[i] 就是对第i个字符串的第一个字符取值了 cout只会打印第i个字符串的第1个字符
		cout<<argv[i]<<endl;
	}
	return 0;
}


/* 
1.argc是参数个数（至少为1，argv[0]是程序名）

2.argv是指针字符串组，每个元素是char*指向一个字符串参数

3.argv[i]指向第i个字符串的第一个字符地址，cout遇到char*会一直打印到\0，所以输出整个字符串

4.*argv[i]是对第i个字符串的第一个字符取值，cout只会打印单个字符
*/