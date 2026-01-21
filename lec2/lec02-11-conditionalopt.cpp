#include <iostream>
using namespace std;

int main() {
	
	int a, b;
	cout << "Input a and b" << endl;
	cin >> a >> b;

	int res;
	if (a>b)
	    res=a;
	else
	    res=b;
	//关于 if else 单行 statement还是需要把else标出来并且有缩进的
	cout << "the larger number is: " << res << endl;


    return 0;
}

//等效于一个三元写法
int main() {
	
	int a, b;
	cout << "Input a and b" << endl;
	cin >> a >> b;

	int res;
	a>b?res=a:res=b;
	//关于 if else 单行 statement还是需要把else标出来并且有缩进的
	cout << "the larger number is: " << res << endl;


    return 0;
}
