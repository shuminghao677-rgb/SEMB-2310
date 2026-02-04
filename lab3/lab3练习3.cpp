#include <iostream>
using namespace std;

int main(){
    int size;
    cout<<"Enter the number of rows:"<<endl;
    cin>>size;
    if (size<=0){
        cout<<"Enter the number of rows:"<<endl;
    }else{
        size=size;
    }
    int matrix[size][size];
    for(int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            matrix[i][j]=0;
        }
    }
    for(int i=0;i<size;i++){
        int count=0;
        for (int j=i;j<size;j++){
            matrix[i][j]=count;
            count++;

        }
    }
    for(int j=0;j<size-1;j++){
        int count=1;
        for (int i=j+1;i<size;i++){
            matrix[i][j]=count;
            count++;

        }
    }

    for(int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}