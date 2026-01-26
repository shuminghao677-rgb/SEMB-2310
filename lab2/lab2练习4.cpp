#include <iostream>
#include <cmath>
using namespace std;
#include <iomanip>
int main(){
    cout<<"Enter the value of a, b and c for quadratic equation:"<<endl;
    double a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    cout<<setprecision(1);
    cout<<fixed;
    if (b*b-4*a*c==0){
        double sol;
        sol=-b/(2*a);
        cout<<"The Quadratic Equation has two equal real roots: "<<sol<<endl;
    }else if (b*b-4*a*c>0){
        double sol1,sol2;
        sol1=(-b+sqrt(b*b-4*a*c))/(2*a);
        sol2=(-b-sqrt(b*b-4*a*c))/(2*a);
        cout<<"The Quadratic Equation has two real roots: "<<sol1<<" and "<<sol2<<endl;
    }
    else{
        double sol3,sol4;
        sol3=-b/(2*a);
        sol4=sqrt((4*a*c-b*b))/(2*a);
        cout<<"The Quadratic Equation has two Complex roots:"<<endl;
        cout<<sol3<<"+"<<sol4<<"i"<<endl;
        cout<<sol3<<"-"<<sol4<<"i"<<endl;
    }
    return 0;
}