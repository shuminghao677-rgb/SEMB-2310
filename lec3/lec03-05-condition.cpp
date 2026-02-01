#include <iostream>
using namespace std;

int main() {
	
	int k;
	cout<<"please enter the integer k"<<endl;
	cin>>k;

    if (k>2 && k<7) {
		//必须用 && 不能直接  2<k<7
		cout << "true, the k is with the range 2-7" << endl;
	} else {
		cout << "false, the k is not in the range 2-7" << endl;
	}
	
	return 0;
}
