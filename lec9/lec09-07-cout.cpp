#include <iostream>
#include <string>
using namespace std;

class Student {
	public:
		Student(string name="", int age=0) {
			mName = name;
			mAge = age;
		}
		
	public:
		string mName;
		int mAge;
};

ostream& operator<<(ostream &cout, Student &s) {
	cout << s.mName << "-" << s.mAge;
	return cout;
}

int main() {

	Student s1("Bob", 20), s2("Bob", 20), stu_list;

	Student s3;

	return 0;
}
