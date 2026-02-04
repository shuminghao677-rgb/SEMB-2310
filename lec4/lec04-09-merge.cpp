#include <iostream>
#include <cstring>
using namespace std;



int main() {

	char str1[50], str2[50];

	cout << "Input String 1: ";
	cin >> str1;
	cout<<"初始的str1是:  "<<str1<<endl;
	cout<<endl;

	cout << "Input String 2: ";
	cin >> str2;
	cout<<endl;

	strcat(str1," ");
	strcat(str1,str2); //相当于strcat函数把两个str连在一起 又补了一个null character

	cout<<"此时的str1是:  "<<str1<<endl;
	cout<<"声明的空间是:  "<<sizeof(str1)<<endl;
	cout<<"此时字符串的长度是:  "<<strlen(str1)<<endl; //strlen 是只有'\0'之前的长度

	return 0;
}
