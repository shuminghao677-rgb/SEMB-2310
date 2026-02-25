#include <iostream>
using namespace std;
#include <string>
//* 这是一个标准的bubble sort排序 在排序的过程中可以引入compare函数
// const int N=5;
// void bubble_sort(int arrs[N]){
//     for(int i=0;i<N-1;i++){
//         for(int j=N-1;j>i;j--){
//             if (arrs[j]<arrs[j-1]){
//                 int tmp;
//                 tmp=arrs[j-1];
//                 arrs[j-1]=arrs[j];
//                 arrs[j]=tmp;
//             }
//         }
//     }
// }
//todo 构建一个compare函数 这个函数作为bubble sort交换的条件
int compare(string s1,string s2){
    int len1=s1.length();
    int len2=s2.length(); //取单个字符串的长度
    int min_len=(len1<len2)?len1:len2;
    for(int i=0;i<min_len;i++){ //todo取较为段的长度 比较单一字符的大小
        if (s1[i]>s2[i])return -1; //s1小就返回-1
        if (s1[i]<s2[i])return 1;//s1大就返回1
        else continue; //如果相等就continue 下一轮
    }
    if (len1<len2) return 1; //如果前面字符都相等就比较长度 s1短 return -1
    if (len1>len2) return -1; //s1长就 return 1
    return 0; //如果都一模一样就return 0
}

int main(){
    string fruits[] = {"Banana", "Apple", "Apples", "Cherry", "Banana"};
    //不知道size的时候就在字符串组后面加空的中括号
    int len=sizeof(fruits)/sizeof(fruits[0]); //取字符串组的长度  用来构建遍历结束边界
    for (int i=0;i<len-1;i++){
        for (int j=len-1;j>i;j--){
            if (compare(fruits[j],fruits[j-1])>0){ //todo调用compare函数来冒泡排序
                string tmp;
                tmp=fruits[j];
                fruits[j]=fruits[j-1];
                fruits[j-1]=tmp;
            }
        }
    }
    for (int i=0;i<len;i++){
        cout<<fruits[i]<<endl;
    }
    return 0;
}