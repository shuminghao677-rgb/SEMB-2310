#include <iostream>
using namespace std;

int findMax(int &x,int &y){ //所以这里要用引用传参
	return (x>y)?x:y;
}

int main() {
	int res,input1,input2;
	cout<<"input one number"<<endl;
	cin>>input1;
	cout<<"input an another number"<<endl;
	cin>>input2;
	res=findMax(input1,input2); //这里建立main函数里的输入值和 helper函数的逻辑
	cout << "The larger one of 4 and 3 is: " << res << endl;
	return 0;
}

//如果没有交互直接3 和 4 就不需要


// int findMax(int x,int y){
// 	return (x>y)?x:y;
// }

// int main() {
// 	int res;
// 	res=findMax(3,4);
// 	cout << "The larger one of 4 and 3 is: " << res << endl;
// 	return 0;
// }