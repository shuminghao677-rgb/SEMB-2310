#include <iostream>
using namespace std;

template <typename T>
T func(T a,T b){
    cout<<"template 1 is working, calculation result is:   "<<a+b<<endl;
}

template <typename T>
T func(T a,T b,T c){
    cout<<"template 2 is working, calculation result is:   "<<a+b+c<<endl;
}

void func(int a,int b){
    cout<<"general helper function 1 is working, calculation result is:   "<<a+b<<endl;
}

int main(){
    int a=10;
    int b=20;
    int c=30;
    cout<<endl;
    func(a,b);//优先调用 general helper Function
    cout<<endl;
    func(b,c);
    cout<<endl;

    func<>(a,b);//加上<>强制调用 template Function
    cout<<endl;
    func<>(b,c);
    cout<<endl;

    func(a,b,c);
    cout<<endl;

    char d='a';
    char e='b';
    func(d,e);//和helper Function变量类型不匹配 只能调用模版函数
    cout<<endl;
    return 0;
}

/*
1. 函数重载优先级：普通函数 > 模板函数（类型完全匹配时）

2. 强制调用模板：func<>(a,b) 用空尖括号<>强制选择模板函数

3. 模板参数推导：func(a,b,c) 自动推导 T 为 int，调用三参数模板

4. 类型匹配：func(d,e) 参数为 char，普通函数要求 int，不匹配 → 只能调模板

5. 调用顺序：普通函数(类型匹配) → 模板函数 → 强制模板(<>)
*/