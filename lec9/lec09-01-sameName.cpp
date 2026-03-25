#include <iostream>
using namespace std;

class Course{
	public:
		int score; //是成员变量 当参数和成员变量同名的时候 成员变量加上->
		
		// <等价写法1>
		/* Course(int score){
			this->score=score;
		} */

		// <等价写法2>
		Course(int score):score(score){};
};
int main() {
	Course c(10);
	cout<<"对象c的 score参数是:  "<<c.score<<endl;
	return 0;
}

/*
1. this指针：指向当前对象，区分成员变量和参数

2. 参数名与成员变量同名时，用this->成员变量区分

3. 初始化列表写法：Course(int s) : score(s) {} 可避免this
*/
