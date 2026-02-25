#include <iostream>
using namespace std;
#include <string> //* 本身string 相当于一个类 class 里面有自己的默认构造函数 和 带参数的构造函数

int main() {

	// string str1; //声明字符串
	// string str2("hello world"); //创建字符串
	// string str3(str2); //复制字符串
	// string str4(5, 'a'); //重复构造字符串
	string str1("love");
	string str2(3,'o');//这里重复构造只能是 字符

	string str3(str2);
	string str4; //用for循环实现重复字符串构造
	for (int i=0;i<4;i++){
		str4+=str1;
	}

	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "str3: " << str3 << endl;
	cout << "str4: " << str4 << endl;
	cout << endl;

	/*	
	string str5("cs2310");
	string str6 = str5;
	cout << "str5: " << str5 << endl;
	cout << "str6: " << str6 << endl;
	string str7;
	str7.assign(str6, 2, 4);
	cout << "str7: " << str7 << endl;
	cout << endl;
	*/
	
	/*
	string str8 = "cs";
	str8 += "2310";
	
	str8.append("-computer");

	str8.append("-programming-language", 0, 12);

	cout << "str8: " << str8 << endl;
	cout << endl;
	*/

	/*	
	string str9 = "cs2310";
	//cout << str9.at(6) << endl;
	cout << str9[6] << endl;
	//cout << "str9: " << endl;
	*/

    /*
	string str10 = "cs2310cs";
	int pos = str10.find("cs");
	cout << "pos is: " << pos << endl;
	pos = str10.rfind("cs");
	cout << "pos is: " << pos << endl;

	string str11 = str10.replace(pos, 2, "-computer-programming");
	cout << "str11 is: " << str11 << endl;
	*/

	/*
	string str12 = "cs2310";
	str12.insert(6, "cs");
	cout << "str12 is: " << str12 << endl;
	str12.erase(6);
	cout << "str12 is: " << str12 << endl;
	str12.erase(2, 4);
	cout << "str12 is: " << str12 << endl;

	string str13 = "cs2310";
	string str14 = str13.substr(2, 4);
	cout << "str14 is: " << str14 << endl;
	*/

	/*
	string str15 = "abcd@cityu.edu.hk";
	int index = str15.find('@');
	cout << str15.substr(0, index-0) << endl;
	*/


	/*
	string str16, str17("aab");
	str16 = "aac";
//	str16 = "aaa";
//	str16 = "aabc";
//	str16 = "aa";
//	str16 = "aab";
	cout << str16.compare(str17) << endl;
	*/

	return 0;
}
