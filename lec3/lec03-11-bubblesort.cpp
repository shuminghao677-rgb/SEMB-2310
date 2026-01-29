#include <iostream>
using namespace std;
#define N 10 //超级全局广播

int main(){
    int array[N];
    for (int i=0;i<N;i++){
        cin>>array[i];
    }//先遍历输入
    for (int j=0;j<N-1;j++){//对于bubble sort的外层循环就是数组有多少元素 就进行N-1轮内循环
        for (int k=N-1;k>j;k--){//对于内循环来说 第一次比较N-1次就是最多了 然后每轮比较的次数越来越少 直到等于第几轮轮数
            int tmp;
            if (array[k]<array[k-1]){
                tmp=array[k-1];
                array[k-1]=array[k];
                array[k]=tmp;//需要一个中间变量tmp交换
            }
        }

    }
    for (int q=0;q<N;q++){
        cout<<array[q]<<"  ";//这里是遍历输出
    }
    return 0;
}