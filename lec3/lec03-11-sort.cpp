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

	// TODO: sorting



	// Display the sorted array
	cout << "Sorted array:" << endl;

	for(int i=0; i<N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}


