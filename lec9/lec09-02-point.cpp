#include <iostream>
using namespace std;

class Point {
	public:
		int x,y;
		Point(){
			x=0;
			y=0;
		}
		Point(int x,int y){
			this->x=x;
			this->y=y;
		}
		void print() {
			cout << "x = " << x << "; y = " << y << endl;
		}
		Point& setX(int a){
			x=a;
			return *this;
		}
		Point& setY(int b){
			y=b;
			return *this;
		}
};

int main() {
	Point p1(11,22);
	Point p2;
	p1.print();
	p2.setX(33);
	p2.setY(44);
	p2.print();
	return 0;
}


/*
1. 默认构造函数：Point() 初始化x=0,y=0

2. 参数构造函数：Point(int x,int y) 用this区分成员变量和参数

3. 链式调用：setX和setY返回*this（对象自身引用），可实现p2.setX(33).setY(44)

4. print()：成员函数打印坐标
*/