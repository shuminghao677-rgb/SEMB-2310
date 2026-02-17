#include <iostream>
#include <string>

using namespace std;
int main(){
    string input1,input2;
    cout<<"Input String 1:"<<endl;
    cin>>input1;
    cout<<"Input String 2:"<<endl;
    cin>>input2;
    string total;
    total=input1+input2;
    //因为是cpp不是python 所以这里不需要用ord 和 chr 来转换字符和ASCII码
    for (int i=0;i<(int)total.length();i++){
        for(int j=(int)total.length()-1;j>i;j--){
            if (total[j-1]>total[j]){
                char tmp;
                tmp=total[j];
                total[j]=total[j-1];
                total[j-1]=tmp;
            }
        }
    }
    cout<<"Merged String: "<<total<<endl;
    return 0;
}