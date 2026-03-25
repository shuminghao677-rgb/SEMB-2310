#include <iostream>
using namespace std;

class Course {
    public:
        Course (int i, int s): id(i), score(s) {}
		
        int id;
        double score;
};
class CourseAverage{
    public:
        double operator()(const Course& c1,const Course& c2){
            return ((c1.score+c2.score)/2.0);
        }//是 class CourseAverage的functor仿函数 直接用 ca(参数调用函数返回结果)
};


int main() {

    Course c1(1111, 90), c2(2222, 95);
    CourseAverage ca;
    double result=ca(c1,c2);//这里返回的是一个double
    cout<<"两门课的平均分是:  "<<result<<endl;
    return 0;
}

/*
1. Course类：带参构造函数初始化id和score

2. CourseAverage类：重载operator()，实现仿函数(Functor)

3. 仿函数：对象可以像函数一样调用，ca(c1,c2)等价于ca.operator()(c1,c2)

4. 返回值：计算两门课程的平均分，返回double类型
*/