#include <iostream>
using namespace std;
int main(){
cout<<"Enter the size of the array:"<<endl;
int size;
cin>>size;
cout<<"Enter the element in the array:"<<endl;
int nums[size];
for(int i=0;i<size;i++){
    cin>>nums[i];
}
for(int i=0;i<size;i++){
    for (int j=size-1;j>i;j--){
        if(nums[j-1]>nums[j]){
            int tmp;
            tmp=nums[j-1];
            nums[j-1]=nums[j];
            nums[j]=tmp;
        }
    }
}
cout<<"The sorted array is:"<<endl;
for (int i=0; i<size-1;i++){
    cout<<nums[i]<<", ";
}
cout<<nums[size-1]<<endl;
}
