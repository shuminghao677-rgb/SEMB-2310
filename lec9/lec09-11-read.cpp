#include <iostream>
#include <fstream>
using namespace std;

const int BUF_SIZE = 512;

int main() {

	ifstream fin;

	fin.open("lec09-11-department.txt", ios::in);

	if (fin.fail()) {
		cout << "open failed!" << endl;
		exit(1);
	}
	
	

	fin.close();

	return 0;
}
