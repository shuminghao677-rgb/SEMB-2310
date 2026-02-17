#include <iostream>
using namespace std;

int main(){
    char arr[100];
    cout<<"Enter student info (Name then ID):"<<endl;
    cin.getline(arr,100);//一直读取直到回车才停止 读取一整行
    //sizeof 是100 实际定义多长就返回多长
    //strlen 是实际字符串的长度 而且不带着最后的\0 
    int idx=strlen(arr)-1; //这里因为是索引 所以就是strlen -1 定位到最后一位索引

    while (idx>=0 && arr[idx]!=' '){ //while字符串遍历永远是要idx >=0 尤其是倒着循环的时候
        idx--;
    }
    cout<<"Student name is: ";
    for(int i=0;i<idx;i++){
        cout<<arr[i];
    }
    cout<<endl;

    cout<<"Student ID is: ";
    int j=idx+1;
    while (arr[j]!='\0'){  //这个地方就是有两种方法 一种是记录之前len的长度 用for循环 for循环也可是while的那个循环条件
        cout<<arr[j]; //要么就是 遍历到一个arr的尾巴 用不等于'\0'
        j++;
    }
    // for (int j=idx+1;arr[j]!='\0';j++){
    //     cout<<arr[j];
    //     j++;
    // }
    
    cout<<endl;
    return 0;
}
