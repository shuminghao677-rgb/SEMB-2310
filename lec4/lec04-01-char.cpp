#include <iostream>
using namespace std;


int main() {
	
	// print	
	char c = 'b';	//相当于ASCII码和字母之间的转换
	c += 2;
	cout << "c is: " << c << endl; //此时c在加2之后变成了d
	cout<<endl;


	// test if ch is lower-case: Yes or No
	char ch;
	cin>>ch;
	if (ch>='a' && ch<='z'){ //通过判断在不在char ’a‘和’z‘之间判断是不是小写字母
		cout<<endl;
		cout<<"ch是一个lower-case letter"<<ch<<endl;
		ch=ch-('a'-'A');//通过减32从小写转换成大写
		cout<<endl;
		cout<<"ch对应的upper-case letter是"<<ch<<endl;
	} else{
		cout<<endl;
		cout<<"ch是一个upper-case letter"<<ch<<endl;
		ch=ch+('a'-'A');//通过加32从大写转换成小写
		cout<<endl;
		cout<<"ch对应的lower-case letter是"<<ch<<endl;
	}


	// convert a lower-case ch to upper-case


	return 0;
}





























