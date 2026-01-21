#include <iostream>
using namespace std;

// int main() {
    
// 	int N;
// 	cout << "Enter a year: ";
// 	cin >> N;
// 	if (N%4==0 && N%100!=0){
// 		cout<<"it is a leap year";
// 	}else if (N%400==0){
// 		cout<<"it is a leap year";
// 	}else{
// 		cout<<"it is not a leap year";
// 	}

// 	return 0;
// }

int main() {
    
	int N;
	cout << "Enter a year: ";
	cin >> N;
	if ((N%4==0 && N%100!=0) || (N%400==0)){
		cout<<"it is a leap year";
	} else{
		cout<<"it is not a leap year";
	}
	return 0;
}
//合并写法 用||

