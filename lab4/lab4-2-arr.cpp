#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char word[100]; //分别定义 word
    char chars[100]; //定义 chars
    char input[200]; //定义输出 接着对输出进行cin.getline(arr,长度)
    cout<<"The word and chars are:"<<endl;
    cin.getline(input,200);
    int idx=strlen(input)-1; //找中间的空格 并且对两个arr word 和 chars封装 记得最后索引补'\0'
    while (idx>=0 && input[idx]!=' '){
        idx--;
    }
    for (int i=0;i<idx;i++){
        word[i]=input[i];
    }
    word[idx]='\0';

    int k=0;
    for(int j=idx+1;input[j]!='\0';j++){ //这个是j索引处的值不能是'\0'
        chars[k]=input[j];
        k++;
    }
    chars[k]='\0'; //这里因为结束条件是k更新完但已经不再满足循环条件 所以在chars[k]索引处封装

    int len1=strlen(word);
    int len2=strlen(chars);
    int final_idx=-1; //最后的返回结果是 final_idx
    bool match; //布尔值 是match 对于嵌套循环必须全部满足条件才返回true的结果时 一开始是true 
    for (int i=0;i<=len1-len2;i++){
        match=true;//即第一层循环里定义true
        for (int j=0;j<len2;j++){
            if (word[i+j]!=chars[j]){//然后中间只要有一个不满足就变成true 在第二层循环判断
                match=false;
                break;
            }
        }
        if (match){ //最后再第一层循环里if 判断 如果还是true 就更新final_idx
        final_idx=i;
        //break; 如果只找第一个重复chars的索引 就加上break 找到后就结束循环
    }
    } 
    cout<<"The last position of llo is: "<<final_idx<<endl;
    return 0;
}