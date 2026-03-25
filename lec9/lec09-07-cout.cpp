#include <iostream>
#include <string>
using namespace std;

class Student {
	public:
		string mName;
		int mAge;
	public:
		Student(string name="", int age=0) {
			mName = name;
			mAge = age;
		}
};
ostream &operator<<(ostream &cout,Student &s1){
	cout<<"学生的姓名和年龄是:  "<<s1.mName<<" and "<<s1.mAge<<endl;
	return cout;
}

int main() {

	Student s1("Bob", 20), s2("Bob", 20), stu_list;
	Student s3;//此时 stu_list 和 s3都是默认构建对象
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	return 0;
}

/*
1. 默认构造函数：参数提供默认值，可作无参构造函数使用

2. 友元函数（全局）：ostream &operator<< 重载输出运算符，必须在全局作用域

3. 参数引用：ostream &cout 避免拷贝，Student &s1 避免拷贝

4. 返回引用：return cout 支持链式输出（cout << s1 << s2）

5. 输出格式：自定义学生信息的打印方式
*/