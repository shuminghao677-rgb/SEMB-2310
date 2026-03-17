#include <iostream>
using namespace std;

int main(){
    int size;
    cout<<"Please input the size of the matrix: "<<endl;
    cin>>size;
    cout<<"Please input the matrix row by row:"<<endl;
    int squar[100][100];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin>>squar[i][j];
        }
    }
    cout<<"The clockwise spiral form of the matrix is: "<<endl;
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
    int mid=(size-1)/2;
    if(size%2==1){
        cout<<squar[mid][mid]<<" ";
    }
    return 0;
}
