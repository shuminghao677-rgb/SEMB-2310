#include <iostream>
using namespace std;


int exp(int n,int p){
	if (p==0){
		return 1;
	} else {
		return n*exp(n,p-1);
	}
}
//我觉得这个 可以背一下 就是 exp 还有factorial 的递归和迭代写法
int main() {
	int n, p;
	cout << "Enter n and p: ";
	cin >> n >> p;
	int result;
	result=exp(n,p);
	cout<< "the result is "<<result<<endl;
	return 0;
}
