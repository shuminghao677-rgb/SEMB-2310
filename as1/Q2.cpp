//examples
// 2147483647
// Please enter an integer number:
// 3-digit Segment(s):
// 002 Two
// 147 Seven
// 483 Three
// 647 Seven


// 1
// Please enter an integer number:
// 3-digit Segment(s):
// 001 One

#include <iostream>
#include <vector> //!这里用了vector也就是字符列表和字符串列表在不知道长度的情况下就要用vector 
//!push_back功能类似append
#include <string>
using namespace std;

int main(){
    cout<<"Please enter an integer number:"<<endl;
    int num;
    cin>>num;
    string s=to_string(num); // * 还是基本的把数字转化成字符串
    if ((int)s.length()%3==0){
        s=s;
    } else if((int)s.length()%3==1){ //!这里是string的长度用length但如果是vector就用size()
        s=string(2,'0')+s; // * 正常相加字符串
    } else {
        s=string(1,'0')+s;
    }
    vector<string> seg_list; // !像python一样建立字符串list 然后对满足条件的append是vector和 push_back
    vector<char> digit_list; // !这个是只有char 字符
    for(int i=0;i<(int)s.size();i=i+3){
        seg_list.push_back(s.substr(i,3));//! 关于字符串切片室s.substr(i,3) 从i开始长度是3
        digit_list.push_back(s[i+2]);
    }
    cout<<"3-digit Segment(s):"<<endl;
    for(int i=0;i<(int)seg_list.size();i++){ //! 还是对于vector的长度是size
        string text;
        if (digit_list[i]=='0'){ //* 还是这里判断的是字符是不是0 要用单引号
            text="Zero";
        } else if (digit_list[i]=='1'){
            text="One";
        } else if (digit_list[i]=='2'){
            text="Two";
        } else if (digit_list[i]=='3'){
            text="Three";
        } else if (digit_list[i]=='4'){
            text="Four";
        } else if (digit_list[i]=='5'){
            text="Five";
        } else if (digit_list[i]=='6'){
            text="Six";
        } else if (digit_list[i]=='7'){
            text="Seven";
        } else if (digit_list[i]=='8'){
            text="Eight";
        } else if (digit_list[i]=='9'){
            text="Nine";
        } 
        cout<<seg_list[i]<<" "<<text<<endl;
    }
    return 0;
}