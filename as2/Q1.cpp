//as2 回字螺旋模型

#include <iostream>
using namespace std;
//回字读矩阵 矩阵的回字排列

int main(){
    int size;
    cout<<"Please input the size of the matrix: "<<endl;
    cin>>size;
    cout<<"Please input the matrix row by row:"<<endl;
    int squar[100][100];//先要一个大容量的squar的矩阵
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin>>squar[i][j];
        }
    }
    cout<<"The clockwise spiral form of the matrix is: "<<endl;
    //封装好在 size*size的矩阵里 然后现在需要开始回形读取 用左右双指针
    int start=0;
    int end=size-1;
    while(start<end){
        for(int j=start;j<end;j++){
            int i=start;
            cout<<squar[i][j]<<" ";
        }
        for(int i=start;i<end;i++){
            int j=end;
            cout<<squar[i][j]<<" ";
        }
        for(int j=end;j>start;j--){
            int i=end;
            cout<<squar[i][j]<<" ";
        }
        for(int i=end;i>start;i--){
            int j=start;
            cout<<squar[i][j]<<" ";
        }
        start++;
        end--;
    }
    int mid=(size-1)/2; //因为是 cpp自动取整；
    if(size%2==1){
        cout<<squar[mid][mid]<<" ";//如果是奇数还需要补上最中间的
    }
    return 0;
}

// 知识点
// 1. start=0 end=size-1 和 二分查找一样 指针是索引 while start<end 循环条件 之后所有上下左右遍历都用start和end 
// 更新的地方 start++ end-- 然后循环结束 如果是奇数 mid=(size-1)/2 这个在轴对称图形里也用到过 square[mid][mid]最中间的不要落下是回字的结束

