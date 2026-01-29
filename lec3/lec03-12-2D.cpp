#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double array1[2][3] = {{1.2, 1.34, 2.564}, {3, 4.123, 4}};
	double array2[3][2];
	for (int i =0;i<2;i++){
		for (int j=0;j<3;j++){
			array2[j][i]=array1[i][j];
			cout<<setprecision(2);
			cout<<fixed;
			cout<<array2[j][i]<<"\t";

		}
		cout<<endl;
	}

	return 0;
}
