#include <iostream>
using namespace std;

int main() {
	int count[10]={0}; //在构造一个数组的前提上 先填充0占位
	int digit;

	cout<<"输入十个0-9的自然数,并且输入“-1”结束"<<endl;
	// Get input & calcuate
	while(cin>>digit && digit!=-1){ //把cin输入写在while循环里面 只要不是-1 就可以一直输入
		if (digit>=0 && digit<=9){ //只要输入是0-9索引，就可以在数组的digit位上加一count
			count[digit]++;
			//相当于count长度是10 输入哪个索引，就在哪个索引的次数上加1
		}
	}

	// Display the result
	cout<<"最后的结果数组是：  "<<endl;
	for (int i=0;i<10;i++){
		cout<<count[i]<<"   ";
	}
	//cout << i << " occurs " << count[i] << endl;

    return 0;
}

























