#include <iostream>
using namespace std;

class A{
    private://两个私有变量
        double num1;
        double num2;
    public:
        A(){
            num1=0;
            num2=0;
        }

        A(double n1,double n2){
            num1=n1;
            num2=n2;
        }
        double  getNum1(){
            return num1;
        }

        friend ostream& operator<<(ostream& os,const A& a);//所以先要声明友元函数 对私有变量

        A operator+(const A& other){
            return A(this->num1+other.num1,this->num2+other.num2);//一个加法的overloading
        }
};

ostream& operator<<(ostream& os,const A& a){//一个打印的 overloading
    os<<"这个是A的参数:  "<<a.num1<<"和  "<<a.num2<<endl;
    return os;
}

class A1:public A{
    public:
        virtual double print()=0;
    //A1 因为是有纯虚函数 所以不能创建 A1对象 和 new A1() 赋值 但是可以创建 指向base对象的指针
    //A1 *a1ptr = new A2();
};

class A2:public A1{
    public:
        double print()override{
            return getNum1();
        }
};