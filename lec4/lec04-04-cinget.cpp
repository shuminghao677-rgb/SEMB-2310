#include <iostream>
using namespace std;

int main() {
	char c; //声明一个character 也就是一个字符串里面单一字符遍历进行赋值
	char arr[5]; //这就是固定这个字符串最多是4个字符加上一个null character
	int i=0;
	cout<<"enter something"<<endl;
	while(cin.get(c)&&c!='\n'&&i<4){ //遍历复制的条件就是 当i小于可以赋值的最小size 字符不能是'\n' 公式用的是cin.get(c)
		arr[i++]=c; //遍历用c赋值
	}
	arr[i]='\0'; //最后手动添加 '\0' null character
	cout<<arr<<endl;
	return 0;
}
