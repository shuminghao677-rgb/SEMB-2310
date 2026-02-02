#include <iostream>
#include <algorithm> //使用max函数 需要引用 algorithm
#include <climits> //对于找最大最小值需要提前initiate一个负无穷或者正无穷
using namespace std;

int main(){
    cout<<"Enter the size of the array:"<<endl;
    int size;
    cin>>size;
    cout<<"Enter the elements of the array:"<<endl;
    int nums[size];
    for(int i=0;i<size;i++){
        cin>>nums[i];
    }
    int nums2[size];
    for(int i=0;i<size;i++){
        int max0=INT_MIN; //这里是设置负无穷
        for (int j=i+1;j<size;j++){
            max0=(nums[j]<nums[i])? max(max0,nums[j]):max0; //三元条件 只有当右边大于当前的时候才更新最大值变量
        }
        if (max0==INT_MIN){ //不是负无穷 也就是存在过最大值 才赋值max0 不然直接赋值-1
            nums2[i]=-1;
        } else {
            nums2[i]=max0;
        }
        
        }
cout<<"The output is:"<<endl;
for(int i=0; i<size-1;i++){
cout<<nums2[i]<<", ";
}
cout<<nums2[size-1]<<endl;
}