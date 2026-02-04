#include <iostream>
#include <cstring>
using namespace std;

int main() {

	char str1[20] = "Hello World";
	cout<<str1<<endl;

	char str2[5]; //str2 长度只有5 最后一个是null
	strncpy(str2,"Hello World",4); //只取前四个
	str2[4]='\0';//手动添加 null 手动补'\0'
	cout<<str2<<endl;


	char str3[] = "Hello World";
	cout<<str3<<endl;

	char str4[20]="Hello World";
	strcpy(str4,"happy");//这是使用strcpyhappy把hello覆盖上了 后面跟着一个null 返回的时候只返回null之前
	cout<<str4<<endl;
	cout<<str4[6]<<endl; //但是对null后面索引也会打印出来

	return 0;
}
