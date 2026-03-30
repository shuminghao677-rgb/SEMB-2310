#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    ifstream if1;
    if1.open("/Users/fanxinyun2/Documents/c++算法冲刺/SemB-2310/lab9/lab09.txt");
    if(!if1){
        cout<<"fail to open the target file."<<endl;
        return 1;
    }
    int n;//学生个数 读取整数变量
    if1>>n;// 这个意思是 从头开始读if1的第一个数字
    char comma;
    string name, id, tel;

    ofstream of1;
    of1.open("/Users/fanxinyun2/Documents/c++算法冲刺/SemB-2310/lab9/lab09_output.txt");
    for(int i=1;i<=n;i++){
        if1>>name>>comma>>id>>comma>>tel;
        cout<<"第"<<i<<"位学生:  "<<name<<"   "<<id<<"   "<<tel<<endl;
        of1<<"Student    "<<i<<":"<<endl;
        of1<<"Name:   "<<name<<endl;
        of1<<"Student ID:   "<<id<<endl;
        of1<<"Tel:   "<<tel<<endl;
        of1<<endl;
        cout<<endl;
    }
    if1.close();
    of1.close();
    cout<<"The file has been written already, please check the lab09_output.txt"<<endl;
    return 0;
}


