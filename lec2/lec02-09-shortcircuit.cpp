#include <iostream>
using namespace std;

int main() {
    
	int i=-1, j=-2, k=-3;

	k = (i=2) && (j=2);   	//
	cout << i << " " << j << " " << k << endl;

	k = (i=0) && (j=3);		//
	cout << i << " " << j << " " << k << endl;

	k = i || (j=4);			//
	cout << i << " " << j << " " << k << endl;

	k = (i=2) || (j=5);	    //
	cout << i << " " << j << " " << k << endl;

	return 0;
}
