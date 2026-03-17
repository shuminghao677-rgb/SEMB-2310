#include <iostream>
using namespace std;

class Student{
    public:
        int *pid=nullptr; //声明指针
        int age=0;

        Student(int i,int a):age(a){ // age一个人在初始化列表
            pid=new int(i); //因为需要动态分配内存 所以也需要每个class一个 解析构造函数
            age=a;
            cout<<"调用参数构造函数，pid的地址是:  "<<pid<<endl;
        }
        ~Student(){
            if(pid!=nullptr){//只要指针不是空指针 就要 delete加上pid=nullptr
                delete pid;
                pid=nullptr;
                cout<<"解析构造函数被调用，pid内存被释放"<<endl;
            }
        }//每个对象class一个解析构造函数就够了

        Student(const Student &s){
            pid=new int(*s.pid);//int里放的是值 所以要先*pid取值然后再分配动态内存
            age=s.age;
            cout<<"引用拷贝函数被调用，pid的地址是:  "<<pid<<endl;
        }

        void show(){
            cout<<"该学生的学号是:  "<<*pid<<endl;
            cout<<"该学生的年龄是:  "<<age<<endl;
        }
};
void f() {
    Student stu1(11111,11);
    Student stu2(stu1);
    stu1.show();
    stu2.show();
}

int main() {
    // Student stu; //!一旦有其他函数就不存在默认构造函数但是可以自己定义
    // stu.show();
    f();
    Student stu3(33333,13);
    stu3.show();
    Student stu4(stu3);
    stu4.show();
    Student stu5(55555,15);
    stu5.show();
    return 0;
}


