#include <iostream>
#include <cmath>
#include <string>  //名字字符串参数 所以需要 #include <string>
#include <algorithm> //因为用了 sort 函数 sort函数在 algorithm头文件里面
using namespace std;

class Triangle { //建类Triangle
public: //分为 public 公共部分
    int A,B,C; //于三角形类最重要的就是三条边 A B C 之后所有写在class public 里面的函数用 ABC 都不需要再写参数

    //todo 这两个都是class public 里重要组成部分 都是必须写的 默认构造函数加上初始构造函数
    Triangle():A(0),B(0),C(0){} //默认构造函数  是没有参数的构造函数 相当于没有slides 这个时候默认他的三条边都是0
    Triangle(int a,int b,int c):A(a),B(b),C(c){} //初始构造函数 接收外部数据的构造函数

    //todo member functions 无论是void 不返回值的和返回其他变量类型的函数
    bool isTri(){ // *返回布尔值 判断是不是三角形 A+B>C && A+C>B && B+B>A 是判断三条边能不鞥围城三角形的标准条件表达式
        if(A+B>C && A+C>B && B+C>A){
            return true;
        }else{
            return false;
        }
    }

    void getArea(string n=""){ //Default Argument 如果是空就默认是""空字符串这样子好去写if条件 来证明没有传参
        double area=0;//初始area=0 也就是对后面无论能不能围城三角形 不能围成三角形就说area=0
        double s; //* 初始变量s 用cmath头文件 s=(A+B+C)/2.0 area=sqrt(s*(s-A)*(s-B)*(s-C))
        //todo 在能围城三角形的情况下计算面积 area有个固定公式 s=(A+B+C)/2.0 area=sqrt(s*(s-A)*(s-B)*(s-C))
        if(isTri()){
            s=(A+B+C)/2.0;
            area=sqrt(s*(s-A)*(s-B)*(s-C));
        }

        //todo 这里主要是看有没有传参 getArea(string n="") 这里就是说如果没有对象名字的传参 n就是""，这里if判断条件正好就是！n.empty()不为空的时候就是有传参
        if(!n.empty()){
            cout<<"Area of Triangle (i.e. "<<n;
            if(A!=0 && isTri()){ //只有就是有三边才会有括号内详细的side信息
                cout<<" with sides "<<A<<", "<<B<<" and "<<C<<")";
            }else{
                cout<<")";//没有的话就直接“）”
            }
            cout<<": "<<area<<endl; //无论有没有三边 都打印area
        }else{ //如果没有名字传参的话就是直接 Area of Triangle: area 这种就是出现输入 cin 获取数值的时候
            cout<<"Area of Triangle: "<<area<<endl;
        }
    }
};

int main(){
    Triangle triangle1; //调用默认构建函数 Triangle 三角形的名字；
    triangle1.getArea("triangle1"); //对三角形调用 member 函数 里面传名字参了
    Triangle triangle2(3,4,5); //调用带参数的构建函数 Triangle 三角形的名字()里面有参数
    triangle2.getArea("triangle2"); //对三角形调用 member 函数 里面传名字参了

    int x,y,z;//声明三个变量就是通过用户输入数值 赋值给 xyz
    cout<<"Enter New Sides for Triangle: "<<endl;
    cin>>x;
    cin>>y;
    cin>>z;

    int sides[3]={x,y,z}; //int sides[3]={s,y,z}建立数组 int数字 sides【3】长度为3的数组={}用大括号表示
    sort(sides,sides+3); //algorithm 的头文件对sides数组进行排序sort(头位置，尾位置)因为是数组 数组本身其实就是第一个元素的指针 +3就是尾元素的位置了

    triangle1.A=sides[0];//和调用 member function的时候一样给 A B C赋值其实就是 有点像object的 attribute 和 method
    triangle1.B=sides[1];//int A，B，C class构建的对象的参数 就是attribute 他的member function 就是method
    triangle1.C=sides[2];

    triangle1.getArea();//没有进行名字传参的调用 member function
    return 0;
}