#include <iostream>
#include <cmath>
using namespace std;
const double pi=3.14;

class Shape{
    public:
        virtual double getArea()=0;//纯虚函数
        virtual void print()=0;//纯虚函数
        virtual ~Shape(){}
};

class Circle:public Shape{
    public:
        double radius;
        Circle(double r):radius(r){}
        double getArea(){
            return pi*radius*radius;
        }
        void print(){
            cout<<"圆形半径是:  "<<radius<<endl;
            cout<<"圆形面积是:  "<<this->getArea()<<endl;
        }
};

class Rectangular:public Shape{
    public:
        double length,width;
        Rectangular(double l,double w):length(l),width(w){}
        double getArea(){
            return length*width;
        }
        void print(){
            cout<<"长方形长,宽是:  "<<length<<" , "<<width<<endl;
            cout<<"长方形面积是:  "<<this->getArea()<<endl;
        }
};

class Triangle:public Shape{
    public:
        double A,B,C;
        Triangle(double a,double b,double c):A(a),B(b),C(c){}
        double getArea(){
            double s=(A+B+C)/2.0;
            return sqrt(s*(s-A)*(s-B)*(s-C));
        }
        void print(){
            cout<<"三角形三条边是:  "<<A<<" , "<<B<<" , "<<C<<endl;
            cout<<"三角形面积是:  "<<this->getArea()<<endl;
        }
};

int main(){
    int n;
    cout<<"请输入图形的个数"<<endl;
    cin>>n;
    Shape **arr=new Shape*[n];//双重指针 分配内存
    char type;
    double a,b,c;
    for(int i=0;i<n;i++){
        cout<<"请选择一个图形 圆形(c),长方形(r),三角形(t)"<<endl;
        cin>>type;
        switch(type){
            case 'c':{
                cout<<"选择圆形,请输入一个参数"<<endl;
                cin>>a;
                arr[i]=new Circle(a);
                break;
            }
            case 'r':{
                cout<<"选择长方形,请输入两个参数"<<endl;
                cin>>a>>b;
                arr[i]=new Rectangular(a,b);
                break;
            }
            case 't':{
                cout<<"选择三角形,请输入三个参数"<<endl;
                cin>>a>>b>>c;
                arr[i]=new Triangle(a,b,c);
                break;

            }
            default:{
                cout<<"没有所选图形"<<endl;
                arr[i]=nullptr;
                break;
            }
        }
        cout<<"这是第"<<i+1<<"个图形"<<endl;
        arr[i]->print(); 
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=nullptr){
            delete arr[i];
            arr[i]=nullptr;
        }
    }
    delete []arr;
    arr=nullptr;
    return 0;  
}



/*
1. 抽象基类(Shape)：包含纯虚函数 getArea() 和 print()，定义接口规范

2. 虚析构函数(virtual ~Shape())：确保 delete 基类指针时调用派生类析构

3. 派生类(Circle/Rectangular/Triangle)：重写所有纯虚函数，成为具体类

4. 初始化列表：Circle(double r):radius(r){} 直接初始化成员，效率高

5. 多态数组：Shape** arr = new Shape*[n] 双重指针，动态存储不同派生类对象

6. 堆内存分配：new Circle(a) 在堆上创建对象，需手动 delete

7. 释放顺序：先循环 delete 每个对象，再 delete[] 指针数组（与分配相反）

8. this->getArea()：明确调用当前对象的虚函数，实现多态
*/