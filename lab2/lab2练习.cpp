#include <iostream>
using namespace std;

int main(){
    int num1;
    cin>>num1;
    int f1;
    f1=num1/1000;
    int f2;
    f2=(num1-1000*f1)/100;
    int f3;
    f3=(num1-1000*f1-100*f2)/10;
    int f4;
    f4=(num1-1000*f1-100*f2-10*f3)/1;
    cout<<f1+f2+f3+f4<<endl;
    return 0;
}