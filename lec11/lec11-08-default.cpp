#include <iostream>
using namespace std;

template <typename T,typename U=int>
class C{
    public:
        T a;
        U b;
        C(T n1,U n2):a(n1),b(n2){}
        void print(){
            cout<<"Class(print 1): "<<a<<"  "<<b<<endl;
        }
};

template <typename T,typename U=int>
void print(const C<T,U>& c){
    cout<<"Class(print 2): "<<c.a<<"  "<<c.b<<endl;
}

int main(){
    cout<<endl;
    C <string> c1("CS",2310);
    c1.print();
    cout<<endl;
    C <int> c2(2,1);
    print(c2);
    cout<<endl;
    return 0;
}

/*
1. 类模板默认参数：template <typename T, typename U=int>，U 默认为 int

2. 使用默认参数：C<string> c1("CS",2310) 等价于 C<string,int> c1("CS",2310)

3. 构造函数：C(T n1, U n2):a(n1),b(n2){} 用初始化列表初始化成员

4. 成员函数 print()：打印对象自身的成员变量

5. 全局函数模板：void print(const C<T,U>& c) 接收 C 类对象，有默认参数

6. 类型推导：C<int> c2(2,1) 推导 T=int, U=int（使用默认值）

7. 输出结果：c1.print() → "CS 2310"；print(c2) → "2 1"
*/