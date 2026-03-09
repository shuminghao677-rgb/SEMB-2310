#include <iostream>
using namespace std;

int comparison(string s1,string s2){
    int i=0;
    int len1=(int)s1.length();
    int len2=(int)s2.length();

    while (i<len1&&i<len2){
        if (s1[i]<s2[i]){
            return -1;
        } else if (s1[i]>s2[i]){
            return 1;
        } else {
            i++;
        }
    }
    if (len1<len2){
        return -1;
    } else if (len1>len2){
        return 1;
    } else {
        return 0;
    }
}
void swap(string &s1,string &s2){ //!这里进行引用传参 要改变原值
    string tmp;
    tmp=s1;
    s1=s2;
    s2=tmp;
}
int main(){
    int n;
    cout<<"Enter the number of the strings:"<<endl;
    cin>>n;
    cout<<"Enter the contents of each string:"<<endl;
    // !int arr[n]; 
    string arr[n];

    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        for (int j=n-1;j>i;j--){
            int result;
            result=comparison(arr[j-1],arr[j]);
            if (result==1){
                swap(arr[j-1],arr[j]);
            } else {
                continue;
            }
        }
    }
    cout<<"The sorted strings are:"<<endl;
    for (int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}

/* 
1.冒泡排序核心：需要两层嵌套循环，外层控制比较轮数，内层控制每轮的相邻比较

2.字符串比较：用自定义comparison函数返回-1/0/1决定大小关系

3.交换函数关键：必须用引用传参(string &s1, string &s2)才能改变原数组元素
*/ 
