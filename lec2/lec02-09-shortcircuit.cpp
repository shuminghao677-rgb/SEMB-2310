#include <iostream>
using namespace std;

int main() {
    
	int i=-1, j=-2, k=-3;

	k = (i=2) && (j=2);   	//i==2 j==2 true k==1
	cout << i << " " << j << " " << k << endl;

	k = (i=0) && (j=3);		//i==0 j不执行赋值 j==2 k==0
	cout << i << " " << j << " " << k << endl;

	k = i || (j=4);			//i依旧==0 因为是||j==4 true k==1
	cout << i << " " << j << " " << k << endl;

	k = (i=2) || (j=5);	    //i==2 左边已经是true了 j不执行赋值 j==4 true k==1
	cout << i << " " << j << " " << k << endl;

	//short circuit used to improve the efficiency

	return 0;
}
