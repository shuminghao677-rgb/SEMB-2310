#include <iostream>
using namespace std;
#include <iomanip>


int main(){
    double p;//除法后的结果不是integer 是double
    int a,b,c;
    cout<<"Enter the first side:"<<endl;
    cin>>a;
    cout<<"Enter the second side:"<<endl;
    cin>>b;
    cout<<"Enter the third side:"<<endl;
    cin>>c;
    p=(a+b+c)/2.0;//如果不是 2.0 整数除法会舍掉后面的.5
    double S;//double
    S=sqrt(p*(p-a)*(p-b)*(p-c));//pow(num1,num2)公式
    cout<<setprecision(2);//保留两位小数
    cout<<fixed;
    cout<<"The area is:"<<S<<endl;
    return 0;
}