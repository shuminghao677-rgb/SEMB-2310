#include <iostream>
using namespace std;

int count(int num){

	if (num==0){
		return 1;
	} else if (num<10 && num>-10){
		return 0;
	} else {
		return count(num/10)+count(num%10); //分成商和余数部分  然后结束条件就是 只有等于0才返回1 如果是其他数字就是0
	}
}

int main() {
	int n;
	cout << "Enter n: ";
	cin >> n;

	int result=count(n);
	cout<<"The answer is "<<result<<endl;
	return 0;
}

