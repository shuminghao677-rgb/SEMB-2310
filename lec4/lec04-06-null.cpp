#include <iostream>
using namespace std;
#include <cstring>

int main() {

	char s1[] = "Hello"; //第一次赋值 [] 代表会随着后面字符串的长度加\0
	char s2[] = "CS 2310";
	char s3[4]; //strcpy 可以用来更改s3的字符串赋值
	strcpy(s3,"cpp");
	
	cout<<s1<<endl;
	cout<<s2<<endl;

	s1[3]='\0'; //相当于只截取前三位字符
	s2[3]='\0';

	cout<<s1<<endl;
	cout<<sizeof(s1)<<endl;//还是原来s1的长度
	cout<<strlen(s1)<<endl; //只有’\0‘之前的长度

	cout<<s2<<endl;
	cout<<sizeof(s2)<<endl;
	cout<<strlen(s2)<<endl;

	return 0;
}
