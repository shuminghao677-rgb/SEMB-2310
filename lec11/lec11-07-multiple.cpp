#include <iostream>
#include <string>
using namespace std;

template <typename T,typename U>
class C{
    public:
        T a;
        U b;
        C (T n1,U n2): a(n1),b(n2){}//参数构造函数
        void print(){
            cout<<"Class(print1): "<<a<<"  "<<b<<endl;
        }
};

template <typename T,typename U>
void print(const C<T,U>& c){
    cout<<"Class(print2): "<<c.a<<"  "<<c.b<<endl;
} 

int main(){
    cout<<endl;
    C<string,int> c1("CS",2310);
    // C c1(string("CS",2310)); 不可以 必须 explicit specification
    c1.print();
    cout<<endl;

    C <int,int> c2(1,2);
    print(c2);
    cout<<endl;

    return 0;
}

/*
1. 类模板 C<T,U>：两个类型参数，存储两个不同类型的成员变量

2. 构造函数：用初始化列表初始化 a 和 b

3. 成员函数 print()：打印对象自身的成员变量

4. 全局函数 print()：接收 C<T,U> 对象，打印其成员（通过对象访问）

5. 显式指定：C<string,int> c1(...) 必须写模板参数，类模板不支持自动推导（C++17前）

6. 函数模板推导：print(c2) 自动推导 T=int, U=int
*/