#include <iostream>
using namespace std;

int main() {

	char name[5]; //这里是因为John 四个字母 加一个 null character \0
	//name = "John"; 会报错 不能这样赋值

	strcpy(name,"John"); //这里strcpy就是string copy函数
	cout << name << endl;

	return 0;
}
