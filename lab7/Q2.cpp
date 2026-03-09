#include <iostream>
#include <string>
using namespace std;

int comparison(string s1,string s2){
    int i=0;
    int len1=(int)s1.length();
    int len2=(int)s2.length();

    while (i<len1&&i<len2){
        if (s1[i]<s2[i]){
            return -1;
        } else if (s1[i]>s2[i]){
            return 1;
        } else {
            i++;
        }
    }
    if (len1<len2){
        return -1;
    } else if (len1>len2){
        return 1;
    } else {
        return 0;
    }
}
int main(){
    string a,b;
    cout<<"Enter the first string:"<<endl;
    cin>>a;
    cout<<"Enter the second string:"<<endl;
    cin>>b;
    int result;
    result=comparison(a,b);
    if (result==-1){
        cout<<"The second string is larger."<<endl;
    } else if (result==1){
        cout<<"The first string is larger."<<endl;
    } else if (result==0){
        cout<<"The two strings are equal."<<endl;
    } 
    return 0;
}


/* 
1.比较逻辑：先逐字符比较ASCII值，字符不等直接返回结果（-1或1）

2.长度处理：共同部分字符全相等时，较长的字符串更大

3.返回值：-1表示s1<s2，1表示s1>s2，0表示相等

4.循环条件：while(i<len1 && i<len2)保证只在共同长度内比较

5.输出格式：每个测试用例只打印一次提示语和一次结果，用else-if确保单一输出
*/ 