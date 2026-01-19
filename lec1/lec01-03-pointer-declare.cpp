#include <iostream>
using namespace std;

int main() {
	int a1=10;
	int* p1=&a1;
	cout<<endl<<"the original data:"<<endl<<"a1:"<<a1<<endl<<"p1:"<<p1<<endl<<"a1:"<<*p1<<endl;
    *p1=20;
    cout<<endl<<"the modified data"<<"a1:"<<a1<<endl<<endl;
	return 0;
}
