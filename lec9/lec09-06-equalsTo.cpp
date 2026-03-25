#include <iostream>
#include <string>
using namespace std;

class Student {
	public:
		string mName;
		int mAge;

	public:
		Student(string name, int age) {
			mName = name;
			mAge = age;
		}
		bool operator==(const Student &s){
			return(mName==s.mName && mAge==s.mAge);
		}
};

int main() {

	Student s1("Bob", 20), s2("Bob", 20), s3("Tom", 20);
	bool result1=s1.operator==(s2);
	cout<<"结果是:  "<<result1<<endl;
	bool result2=s1.operator==(s3);
	cout<<"结果是:  "<<result2<<endl;
	return 0;
}


/*
1. 构造函数：初始化姓名和年龄

2. 运算符重载==：比较两个Student对象的姓名和年龄是否都相等

3. 调用方式：s1.operator==(s2) 等价于 s1 == s2

4. 返回值：true(1)表示相等，false(0)表示不相等

5. 输出：s1和s2比较返回1，s1和s3比较返回0
*/