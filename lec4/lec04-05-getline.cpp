#include <iostream>
using namespace std;
void printStates();




int main() {
	char s[5];

	while(true) {

        cin.getline(s,5);//只要s的前四位并且自己补\0 


        printStates();//报信息 是一切正常还是有超出

        if (cin.fail()){ //一旦超出size 这个会返回1

        cin.clear(); //相当于先清除报错

        cin.ignore(100,'\n'); //然后把从超出的部分到 enter中间的所有都跳过 在缓存区也清除

        }
        cout<<"output/"<<s<<"/"<<endl;
        
        cout<<endl;

        cout<<"最后字符串是： "<<s<<endl;

        }
	
	return 0;
}





void printStates() {
	cout << "failbit: " << cin.fail() << endl;//超出 size
	cout << "eofbit: " << cin.eof() << endl;
	cout << "badbit: " << cin.bad() << endl;
	cout << "goodbit: " << cin.good() << endl; //一切正常 输入size小于等于4
	cout << endl;
}
