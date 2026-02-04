#include <iostream>
using namespace std;

int main() {

	int sum[13] = {0}; //这个是不是就相当于 python中 sum=[0]*13
	for (int i=1;i<7;i++){
		for (int j=1;j<7;j++){
			sum[i+j]++;
		}
	}
	for(int i=0;i<(sizeof(sum)/sizeof(int));i++){ //这里必须用sizeof来计算数组长度 只有使用动态容器vector的时候可用sum.size()函数计算长度
		cout<<"两个骰子的和是 "<<i<<" 的个数是"<<sum[i]<<endl;
	}
	return 0;
}
