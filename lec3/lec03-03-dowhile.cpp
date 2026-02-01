#include <iostream>
using namespace std;

int main() {

	int n;
	do{
		cout<<"请输入一个大于0的数"<<endl;
		cin>>n;
		if(n<=0){
			cout<<"输入的值小于0，不符合要求，请重新输入"<<endl;
		}//这个结构是可选的 就是相当于重复一下while的条件 就是提示一下 哪里不符合要求
	}
	while(n<=0); //代表只要 n小于0就开始循环 进入重复的do循环

    cout << "n is: " << n << endl;

	return 0;
}
