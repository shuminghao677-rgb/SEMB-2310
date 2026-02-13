#include <iostream>
#include <cmath>
using namespace std;

int getLen(int num){
	if(num==0){
		return 1;
	}
	int len=0;
	while(num>0){
		num/=10;
		len++;
	}
	return len; //必须要返回长度
}

int getValue(int num){
	int len=getLen(num);
	int weight=pow(10,(len/2)); //让10 的二分之len次方 求出来weight 有pow 急需要用 include <cmath>
	int res=num % weight;
	return res;
}

int main() {
	int n;
	cout << "Enter the number: ";
	cin >> n;
	int res;
	res=getValue(n);
	cout << "The value of last half digits of is: "<< res << endl;

	return 0;
}
