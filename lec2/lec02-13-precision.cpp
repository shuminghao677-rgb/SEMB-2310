#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout<<setprecision(2);//不设置setprecision的时候默认是6位有效数字
	cout<<3.14<<endl;
	return 0;
}
//3.1

int main() {
	cout<<fixed;//设置fixed 的时候是默认小数点后面刘伟数字
	cout<<3.14<<endl;
	return 0;
}
//3.140000


int main(){
	cout<<setprecision(2);
	cout<<fixed;//同时设置setprecision 和 fixed 就是小数点后面2位小数
	cout<<3.3<<endl;
	return 0;
}
//3.30

int main(){
	int a=17;
	cout<<oct<<a<<endl;
	cout<<hex<<a<<endl;
	cout<<dec<<a<<endl;
	return 0;
}
//21
//11
//17
