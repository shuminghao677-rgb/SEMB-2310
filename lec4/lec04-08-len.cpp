#include <iostream>
#include <cstring>
using namespace std;

int main() {

	char s[20] = "Hello world";
	//char s[20] = "cs2310";
	cout<<"整个空间长度是不变的:  "<<sizeof(s)<<endl;
	cout<<endl;
	cout<<"实际字符串的长度:   "<<strlen(s)<<endl;
	cout<<endl;
	s[4]='\0';
	cout<<"手动覆盖null character后长度:  "<<strlen(s)<<endl; //strlen 始终是 '\0'之前的长度
	cout<<endl;
	cout<<s<<endl;
	cout<<endl;
	return 0;
}
//一个字符占一个字节 如果是整数的话 就要在数组的基础上除以sizeof(int)