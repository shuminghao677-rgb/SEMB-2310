#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Base{
    public:
        T m,n;
        Base(){}
        Base (T a,T b):m(a),n(b){}

};
class Child1:public Base<string>{
    public:
        Child1():Base("child","01"){}
};

template <typename T>
class Child2:public Base<T>{
    public:
        Child2(){
            cout<<typeid(T).name()<<endl;
        }
};

int main(){
    Child1 c1;
    cout<<c1.n<<"  "<<c1.m<<endl;
    cout<<endl;

    Child2<int> c2;
    cout<<endl;
    cout<<c2.n<<"  "<<c2.m<<endl;

    return 0;

}

/*
1. 基类模板 Base<T>：有默认构造(未初始化)和带参构造(初始化m,n)

2. Child1：普通类继承 Base<string>，构造函数调用 Base("child","01") 初始化

3. Child2：模板类继承 Base<T>，构造函数只打印类型名，不初始化基类成员

4. Child2<int> c2：调用 Child2 构造 → 打印"i" → 调用 Base<int>() 默认构造（m,n未初始化）

5. 输出结果：c1正常输出"child 01"，c2输出随机垃圾值（未定义行为）
*/