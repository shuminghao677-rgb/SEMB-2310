#include <iostream>
using namespace std;

class Course {
	public:
		int score;
		Course (){
			score=0;
		}
		Course (int score) {//默认参数值是0 的参数构造函数
			this->score = score;
		}
		Course operator+(const Course &c){
			Course tmp1;
			tmp1.score=this->score+c.score;
			return tmp1;
		}
		Course operator=(const Course &c){
			if (this->score!=c.score){
				this->score=c.score;
			}
			return *this;//和单独构建某一个参数一个 返回对象自己本身
		}
};

int main() {

	Course c1(100), c2(80), c3,c4;

	// <等价写法1>
	// c3=c1+c2;

	// <等价写法2>
	c3=c1.operator+(c2);
	c4.operator=(c3);

	cout<<"operator +的结果(overloading)是:  "<<c3.score<<endl;

	cout<<"operator +的结果(overloading)是:  "<<c4.score<<endl;

	return 0;
}

/*
1. 默认构造函数：Course() 初始化score=0

2. 参数构造函数：Course(int score) 用this区分成员变量和参数

3. 运算符重载+：Course operator+(const Course &c) 返回临时对象，存储两数之和

4. 运算符重载=：Course operator=(const Course &c) 返回自身引用(*this)，支持链式赋值

5. 调用方式：c3=c1+c2 等价于 c3=c1.operator+(c2)；c4.operator=(c3) 显式调用赋值运算符
*/