#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void f1(vector<int> &v) {
}

void f2(vector<int> &v) {
}


int main() {

	vector<int> v; 

	v.push_back(30);
	v.push_back(20);
	v.push_back(10);
	v.push_back(70);
	v.push_back(80);
	v.push_back(90);

	f1(v);

	return 0;
}
