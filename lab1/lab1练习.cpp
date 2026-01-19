#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

//Q2
// int main(){
//     int i=5;
//     char a='A';
//     i=i-a;
//     char b='D';
//     cout<<b+1<<endl;
//     cout<<"现在的i是:   "<<i;
//     return 0;
// }
// ASCII中A对应65
// 只要是和整数相加 结果基本都是整数

//Q3

int main(){
    int j=3,k=2;
    double y;
    y=j/k;
    //因为j和k 都是整数所以是一个整数除法 结果3/2=1
    //但是因为 y声明过了是double 所以最后的类型是double
    cout<<"y is:  "<<y<<endl;
    cout<<typeid(y).name()<<endl;
    return 0;
}




