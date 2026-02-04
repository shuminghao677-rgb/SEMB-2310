#include <iostream>
using namespace std;

int main() {

	int array[3][4] = { {100, 95, 92, 10}, 
						{80, 60, 98, 10}, 
						{65, 85, 90, 10} };
	
	// number of all elements
	int number_element=sizeof(array)/sizeof(int);//因为都是整数 所以整体矩阵的字节数除以单个整数字节就是整数数量
	cout<<"数组的一共有:  "<<number_element<<"个整数。"<<endl;


	// number of rows
	// == total size of array / size of each row
	int number_row=sizeof(array)/sizeof(array[0]);//用矩阵的字节除以每一行整数的字节 这里是固定array[0]起始字节就是整体字节
	cout<<"数组的一共有:  "<<number_row<<"行整数。"<<endl;

	// number of columns
	int number_column=sizeof(array[0])/sizeof(int);//用矩阵的每一行字节除以单个整数的字节 获得每行有多少个个数也就是column的个数
	cout<<"数组的一共有:  "<<number_column<<"列整数。"<<endl;
	
	return 0;
}
