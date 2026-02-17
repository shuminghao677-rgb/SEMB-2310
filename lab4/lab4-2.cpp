#include <iostream>
#include <string>
using namespace std;

int main(){
    cout<<"The word and chars are:"<<endl;
    string word;
    string chars;
    cin>>word>>chars;
    int idx=-1;
    //滑动窗口思路 用了string.substr(第一个参数是idx索引，然后第二个参数是长度)
    for (int i=0;i<(int)word.length();i++){
        if (word.substr(i,(int)chars.length())==chars){ //substr中的切片和chars相等就更新索引
            idx=i;
        }
    }
    cout<<"The last position of ran is: "<<idx<<endl;
    return 0;
}