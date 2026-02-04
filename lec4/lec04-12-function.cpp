#include <iostream>
using namespace std;


struct Course {
	int id;
	double score;
};

void changing(Course *p){ //用指针设置函数 这里面相当于是用指针 把指针指向的id换成2222
	p->id=2222;
}


int main() {

	Course c = {1111, 100};
	changing(&c); //所以调用函数的时候这里要&加上variable 相当于放的是一个指针


	cout<<c.id<<endl;

	return 0;
}
