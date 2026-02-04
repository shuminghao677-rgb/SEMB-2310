#include <iostream>
#include <cstring>
using namespace std;


int main() {
	struct TA{
		int student_id;
	}; //先设置一个结构体
	struct Course{
		int course_id;
		double score;
		TA myTA; //把之前那个结构体作为类型引入到新的结构体里
	};
	struct Course courses[3];
	for(int i=0;i<(sizeof(courses)/sizeof(Course));i++){
		courses[i].course_id=1111*(i+1);
		courses[i].score=11*(i+1);
		courses[i].myTA.student_id=111*(i+1); //所以这里要先.myta 再.student_id
	}
	for(int i=0;i<(sizeof(courses)/sizeof(Course));i++){
		cout<<courses[i].course_id<<"    "<<courses[i].score<<"    "<<courses[i].myTA.student_id<<endl;
	}
	return 0;
}
