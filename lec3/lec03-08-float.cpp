#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	
	int cnt=1;

	for(float f=1.0; f>0.0; f = f - 0.1) {//第一次进入循环f是1.0 但是之后每次减0.1是近似值
		cout << cnt << endl;
		cnt++;
	}
//如果最后结果是一个小负数就正好是一个十次循环 但如果是一个小正数 就有可能会有11次循环 
	return 0;
}		
//这就是floating point data的特点
		
