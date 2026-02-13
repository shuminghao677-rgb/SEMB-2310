#include <iostream>
using namespace std;


void sort2D(int arr[][4],int row){
	for(int i=0;i<row;i++){
		for (int j=0;j<4-1;j++){
			for (int k=4-1;k>j;k--){
				if (arr[i][k]<arr[i][k-1]){
					int tmp;
					tmp=arr[i][k];
					arr[i][k]=arr[i][k-1];
					arr[i][k-1]=tmp;
				}
			}
		}
	}
}

int main() {
	int y[][4] = {{6, 2, 9, 3},{2, 8, 1, 0},{5, 3, 7, 8}}; // one 2D array that does not know the row numbers
//不知道有几行的时候先为空 只写每一行有4个
	int row = sizeof(y)/sizeof(y[0]); // calculate the number of rows
	sort2D(y,row); //调用2D 每层排序
	cout << "Sorted array is:" << endl;
	for (int i=0; i<3; i++) {
		for (int j=0; j<4; j++) {
			cout << y[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

