#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main(){
    vector<string> words;
    cout<<"Enter the student info:"<<endl;
    string tmp;
    while(cin>>tmp){
        words.push_back(tmp);
    }
    vector<string> ids;
    for (int i=(int)words.size()-1;i>=0;i--){ //!在这种列表遍历删减的时候就必须从后面遍历 不然会跳过
        if (isdigit(words[i][0])){
            ids.push_back(words[i]);
            words.erase(words.begin() + i);
        }
    }
    cout<<"Student name is: ";
    for (int i=0;i<(int)words.size();i++){
        cout<<words[i]<<" ";
    }
    cout<<endl;
    cout<<"Student ID is: ";
    for (int j=0;j<(int)ids.size();j++){
        cout<<ids[j]<<" ";
    }
    cout<<endl;
}