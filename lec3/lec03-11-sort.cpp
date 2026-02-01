#include <iostream>
using namespace std;

const int N = 5;

int main() {
	int a[N];
	cout << "Enter " << N << " numbers:" << endl;

	// Input numbers
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}
	//关于输入循环字段
	// for (int i=0;i<N;i++){
	// 	cin>>a[i];
	// }
	//先提前declare一个array a[N]

	// TODO: sorting
    //这个就是bubble sort 外层是正着遍历，内层是倒着遍历，保持一直在内层索引右边
	for (int i=0;i<N;i++){
		for (int j=N-1;j>i;j--){
			if (a[j]<a[j-1]){
				int tmp;
				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
			}
		}
	}
//一个ascending order

	// Display the sorted array
	cout << "Sorted array:" << endl;

	for(int i=0; i<N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}


