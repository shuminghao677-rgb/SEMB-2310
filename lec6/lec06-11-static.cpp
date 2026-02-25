#include <iostream>
using namespace std;

class Circle{
	public:
		static int cnt_pub; //todo 构建静态变量 特点是所有对象都指向同一变量
		static void print_count(){ //todo 构建静态函数  只能调用静态变量
			cout<<"一共有 "<<cnt_pub<<"个圆"<<endl;
		}
		Circle(){ //todo 构建默认函数
			cnt_pub++; //只要多一个对象 count计数就多一次
		}
		int radius; //这是两个 member variabls
		int area;
		Circle(int r,double a,char s):radius(r),area(a),size(s){ 
			//TODO 带参数的构建函数 initializer list 参数初始化
			//! 构建函数里initialization 顺序必须严格按照变量生命顺序
			//! 先构建函数再声明变量在cpp也是合法的
			if (r>10){ //复杂的赋值在大括号里 输入值的判定用r 赋值用radius 变量名
				size='L';
			} else if(r>5){
				size='M';
			} else{
				size='S';
			}
			cout<<"半径是"<<radius<<"面积是"<<area<<"尺寸是"<<size<<endl;
			cnt_pub++; //带参数的构建函数也需要计数累计
		}
	private: //private 就是只能先被构建函数调用 再main 函数调用class的构建函数被使用
		char size='n';
};

int Circle::cnt_pub=0; //todo class外的初始化静态变量 只能初始化静态变量

int main(){
	Circle c1(3,4,'c');
	Circle c2(11,20,'c'); //c1 c2 两个带参数的构建函数
	Circle c3,c4; //c3 c4两个默认构建函数
	Circle::print_count(); //todo 用类名调用静态函数
	cout<<"最后打印个数"<<Circle::cnt_pub<<endl; //todo 用类名调用静态变量
	return 0;
}
