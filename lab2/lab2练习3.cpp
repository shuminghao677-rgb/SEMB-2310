#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cout<<"Enter the value of A, B and C:"<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    if (a<=0||b<=0||c<=0){
        cout<<"Impossible"<<endl;
    }else if(a+b<=c||b+c<=a||a+c<=b){
        cout<<"Impossible"<<endl;
    }else if(a==b && b==c){
        cout<<"Equilateral"<<endl;
    }else if(a==b ||b==c||c==a){
        cout<<"Isosceles"<<endl;
    }else{
        cout<<"Scalene"<<endl;
    }
    return 0;
}
