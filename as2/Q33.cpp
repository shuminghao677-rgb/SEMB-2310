#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
int sumOfnum(int number){
    int digits=0;
    int copy=number;
    if (copy==0){
        digits=1;
    }else {
        while(copy!=0){
            copy=copy/10;
            digits++;
        }
    }
    int sum=0;
    for(int i=1;i<=digits;i++){
        sum+=(number/(int)pow(10,i-1))%10;
    }
    return sum;
    
}
int main(){
    cout<<"Enter all the numbers (arr): "<<endl;
    int inputs[10];
    for(int i=0;i<10;i++){
        cin>>inputs[i];
    }
    cout<<"Sum of digits for each input number (out):"<<endl;
    for(int i=0;i<10;i++){
        cout<<sumOfnum(inputs[i])<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<"Sorted arrays:"<<endl;
    for(int i=0;i<10-1;i++){
        for(int j=10-1;j>i;j--){
            if(inputs[j-1]>inputs[j]){
                swap(inputs[j-1],inputs[j]);
            }
        }
    }
    for(int i=0;i<10;i++){
        cout<<inputs[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<sumOfnum(inputs[i])<<" ";
    }
    return 0;
    
    
}