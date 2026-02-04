#include <iostream>
using namespace std;

int main() {
	char s1[20], s2[20];//先预留两个位置 说明每个字符串最多存放19个字符 因为还有一个null character
    cin>>s1>>s2;
    cout<<s1<<"   "<<s2<<endl;
    return 0;
}
