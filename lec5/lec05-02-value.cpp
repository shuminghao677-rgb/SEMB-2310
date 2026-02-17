#include <iostream>
using namespace std;

// void f(int y) {
// 	y = 10;
// }
// int main() {
// 	int y = 0;

//     f(y);

// 	cout << "y from main() is: " << y << endl;

// 	return 0;
// }// 这里就是 helper 函数相当于是对复印件的值进行更改不是 直接对值更改需要加 &

void changeValue(int &y){ //引用传递 这样子就对值可以进行修改了
	y=10;
}
int main(){
	int x=0;
	changeValue(x);
	cout<<"The changed value X is "<<x<<endl;
	return 0;
}