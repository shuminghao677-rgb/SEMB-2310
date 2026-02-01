#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double array1[2][3] = {{1.2, 1.34, 2.564}, {3, 4.123, 4}};
	double array2[3][2];
	for (int i =0;i<2;i++){
		for (int j=0;j<3;j++){
			array2[j][i]=array1[i][j];

		}
		cout<<endl;
	}
	for (int i=0;i<3;i++){
		for (int j=0;j<2;j++){
			cout<<"   ";
			cout<<array2[i][j];
			cout<<setprecision(2);
			cout<<fixed;

		}
		cout<<"\t"<<endl;
	}

	return 0;
}

//先是通过循环 调换矩阵的位置 i j 索引互换
//再通过循环打印新的reversed 矩阵，并且输出结果 保留两位小数
//#include <iomanip>
//cout<<fixed;
//cout<<setprescision(2)
//每个嵌套的外层循环打印换行符和制表符来让输出结果呈现矩阵状


