#include <iostream>
using namespace std;

class Shape{
    public:
        void set(int w,int h){
            width=w;
            height=h;
        }
    protected:
        int width,height;
};

class Rectanguler: public Shape{
    public:
        void area(){
            cout<<"Area is: "<<width*height<<endl;
        }
        void perimeter(){
            cout<<"Perimeter is: "<<(width+height)*2<<endl;
        }
};
class PaintCost :public Rectanguler{
    public:
        void paintcost(){
            cout<<"Total paint cost is: "<<231*width*height<<endl;
        }
};

int main(){
    PaintCost p;
    int a,b;
    cout<<"Enter width:"<<endl;
    cin>>a;
    cout<<"Enter height:"<<endl;
    cin>>b;
    p.set(a,b);
    p.area();
    p.perimeter();
    p.paintcost();
    return 0;
}

/* 
1.三层继承：Shape → Rectanguler → PaintCost，子类拥有所有基类的成员

2.保护成员：width和height在Shape中是protected，子类中可以访问

3.方法继承：PaintCost继承了Shape的set()、Rectanguler的area()和perimeter()

4.新增功能：PaintCost添加自己的paintcost()方法，可访问继承来的width和height

5.对象创建：用最底层的PaintCost创建对象，可以调用所有继承链上的方法
*/
