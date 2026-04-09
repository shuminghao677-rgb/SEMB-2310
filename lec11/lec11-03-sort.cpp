#include <iostream>
using namespace std;

template <class T>
void myswap(T& a,T& b){//但是这里交换元素 ab的时候就需要引用传参 因为不是数组类型变量
    T tmp=a;
    a=b;
    b=tmp;
}

template <class T>//因为数组本身就是第一个元素的地址 所以数组不需要引用传参
void mysort(T arr[],int n){
    for(int i=0;i<n-1;i++){
        for (int j=n-1;j>i;j--){
            if (arr[j-1]>arr[j]){
                myswap(arr[j-1],arr[j]);
            }
        }
    }
}

template <class T>
void print(T arr[],int n){
    for(int i=0;i<n;i++){
        if (i==n-1){
            cout<<arr[i]<<"."<<endl;
        }else {
            cout<<arr[i]<<"  ";
        }
    }
}

int main() {
    int arr_int[] = {3, 8, 7, 9, 0, 2, 4, 1, 5, 6};
    int n = sizeof(arr_int) / sizeof(arr_int[0]);
    int arr1[n];
    
    mysort(arr_int,n); //三种模版都是type deduction
    print(arr_int,n);
    cout<<endl;

    char arr_char[] = {'C', 'S', '2', '3', '1', '0'};
    n = sizeof(arr_char) / sizeof(arr_char[0]);

	mysort(arr_char,n);
    print(arr_char,n);
    cout<<endl;
    return 0;
}


/* 
1. 模板函数：myswap(T& a,T& b) 交换两个值，用引用传参直接修改原值

2. 冒泡排序模板：mysort(T arr[],int n) 对任意类型数组排序，调用myswap交换

3. 打印模板：print(T arr[],int n) 通用数组输出函数

4. 类型推导：编译器根据实参自动推导T为int或char
 */