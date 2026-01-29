#include <iostream>
using namespace std;

int main() {

	// int n = 10;
	#define SIZE 10; //把变量写死
	int mark[SIZE];
	for (int i=0;i<SIZE;i++){
		cin>>mark[i];
	}
    
	// TODO: input for all elements
	int sum=0;
	cout<<"[";
    for (int j=0;j<SIZE;j++){
		cout<<mark[j]<<"  ";
		sum+=mark[j];

	}
    cout<<sum<<endl;
	cout<<"]";
	return 0;
}
//输出部分也要用循环 直接 mark就是指针 然后mark[n]里面是数组里面的第几个元素

