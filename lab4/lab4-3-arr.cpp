#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s1[100],s2[100],merge[200];
    cout<<"Input String 1:"<<endl;
    cin>>s1;
    cout<<"Input String 2:"<<endl;
    cin>>s2;

    int count=0; //字符数组接力 count =0 先遍历赋值s1 再遍历赋值s2
    for (int i=0;s1[i]!='\0';i++){
        merge[count]=s1[i];
        count++;
    }
    for (int j=0;s2[j]!='\0';j++){
        merge[count]=s2[j];
        count++;
    }
    merge[count]='\0'; //最后封装 '\0'封装制表符

    int len=strlen(merge);//这个是bubble sort排序 一个是小于 len-1 一个是初始是len-1
    for(int i=0;i<len-1;i++){
        for (int j=len-1;j>i;j--){
            if (merge[j-1]>merge[j]){
                swap(merge[j-1],merge[j]);
            }
        }
    }

    cout<<"Merged String: "<<merge<<endl;
    return 0;
}