#include <iostream>
using namespace std;

class Student {
	public:
		int score;
		int *mID;//student id是指针 所以动态规划

	public:
		Student(int s=0, int id=0) {
			score=s;
			mID= new int(id);
		}
		~Student(){ //析构函数 
			delete mID;//释放内存
			mID=nullptr;//防止野指针
		}
		Student(const Student &s1){
			score=s1.score;
			mID=new int(*s1.mID);
		}
		Student& operator=(const Student &s1){//这里& operator 说明返回*this是返回的原来的对象
			if (this !=&s1){
				delete mID;
				mID=nullptr;
				score=s1.score;
				mID =new int(*s1.mID);
			}
			return *this;
		}
		Student operator+(const Student&s1){ //这里是加法 返回的是临时对象所以不需要 operator前面加引用&来返回原对象
			Student tmp;
			tmp.score=score+s1.score;
			tmp.mID=new int(*mID+*s1.mID);
			return tmp;
		}

	
};

int main() {

	Student s1(100,11111);
	Student s2(200,22222);
	Student s3(0,0);

	s3=s1.operator+(s2);

	cout<<"s3学生的分数是:  "<<s3.score<<endl;
	cout<<"s3学生的学号是:  "<<*s3.mID<<endl;
	return 0;
}


/*
1. 构造函数：默认参数，动态分配mID内存

2. 析构函数：释放动态内存，置nullptr

3. 拷贝构造函数：深拷贝，为新对象分配独立内存

4. 赋值运算符(Student&)：返回引用(*this)，避免额外拷贝，支持链式赋值

5. 加法运算符(Student)：返回临时对象副本，不能返回引用（tmp是局部变量）

6. 三件套完整：析构+拷贝构造+赋值运算符，满足Rule of Three
*/