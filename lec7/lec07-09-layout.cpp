#include <iostream>
using namespace std;

//.data 用来声明已经初始化的全局变量
int global_a=10;
int global_b=20;
int static global_c=30;

//.bss better saved space 用来声明未初始化的全局变量 main entry里都是默认=0
int global_d;
int static global_e;

//.rodata 只读不写的全局变量就是const 变量
const int global_f=40;

int main(){
	cout<<endl;
	cout<<"global_a的地址是"<<(long)&global_a<<endl; 
	//long是用来转化变量类型原来是十六进制 long转化成六十四位 八字节的十进制
	cout<<endl;
	cout<<"global_b的地址是"<<(long)&global_b<<endl;
	cout<<endl;
	cout<<"global_c的地址是"<<(long)&global_c<<endl;
	cout<<endl;
	cout<<"global_d的地址是"<<(long)&global_d<<endl;
	cout<<endl;
	cout<<"global_e的地址是"<<(long)&global_e<<endl;
	cout<<endl;

	//对于字符串的特殊情况 字符串本身就可以看成第一个字符的地址 
	cout<<"cs2310这个字符串的地址是"<<(long)"cs2003"<<endl;//转化为六十位的十进制
	cout<<"cs2310这个字符串的地址是"<<"cs2003"<<endl;//内容本身
	cout<<"cs2310这个字符串的地址是"<<&"cs2003"<<endl;//&对字符串取值
	cout<<"cs2310这个字符串的地址是"<<(void*)"cs2003"<<endl;//打印本身十六进制地址

	return 0;
}


/* 
1.data段：存已初始化的全局/静态变量（如global_a、global_b、global_c）

2.bss段：存未初始化的全局/静态变量（如global_d、global_e），默认值为0

3.rodata段：存const只读变量（如global_f），修改会崩溃

4.(long)强制转换：把十六进制地址转成64位十进制数字打印

5.字符串字面量："cs2003"既是内容也是首字符地址，(void*)强制打印十六进制地址
*/