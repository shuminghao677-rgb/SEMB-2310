#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
	public:
		Student(string n, int a): name(n), age(a) {}
		string name;
		int age;
};

void f() {
	
	Student s1("Alice", 18);
	Student s2("Bob", 19);
	Student s3("Tom", 20);
	Student s4("John", 18);
	Student s5("David", 19);

}


int main() {
	f();
	return 0;
}
