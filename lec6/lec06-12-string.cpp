#include <iostream>
using namespace std;
#include <string> //* 本身string 相当于一个类 class 里面有自己的默认构造函数 和 带参数的构造函数

int main() {

	// string str1; //声明字符串
	// string str2("hello world"); //创建字符串
	// string str3(str2); //复制字符串
	// string str4(5, 'a'); //重复构造字符串
	// string str1("love");
	// string str2(3,'o');//这里重复构造只能是 字符

	// string str3(str2);
	// string str4; //用for循环实现重复字符串构造
	// for (int i=0;i<4;i++){
	// 	str4+=str1;
	// }

	// cout << "str1: " << str1 << endl;
	// cout << "str2: " << str2 << endl;
	// cout << "str3: " << str3 << endl;
	// cout << "str4: " << str4 << endl;
	// cout << endl;

	
/* 	string str5("cs2310");
	string str6 = str5; //这个是复制已有的字符串
	cout << "str5: " << str5 << endl;
	cout << "str6: " << str6 << endl;
	string str7;
	string str8;
	str7=str6.substr(2,4); //这里substr和assign 是等效的但是对于substr来说更好因为是直接生成一个新的str7
	str8.assign(str6, 2, 4); //对于assign就是之前在原有的字符串里面上更改
	cout << "str7: " << str7 << endl;
	cout << "str8: " << str8 << endl;
	cout << endl;
 */
	
	//这是关于添加字符串 一个是+直接相加 还有就是 append语法
	/* 
	string str9="cs";
	str9+="-2310";
	str9.append(" computer");
	str9.append(" programming lecture",0,12);//这里空格也算是一个字符的 
	cout<<"after adding string gradually, final course name is: "<<str9<<endl;
     */

	/*	
	string str9 = "cs2310";
	cout << str9.at(6) << endl;
	cout << str9[6] << endl;
	//cout << "str9: " << endl;
	*/

    /* 
	string str10 = "cs2310cs";
	int pos=str10.rfind("cs"); //这个pos就是position 位置也就是找到字符串cs在str10中第一个字符的索引 倒是后用来替换定位
	//!因为这里有两个cs 所以要替换的是后面的那个就从右边开始找就是 rfind语句 如果是从前面找就是 find语句
	str10=str10.replace(pos,2,"-computer programming");
	cout<<"修改过后的课程名称是"<<str10<<endl;
	 */

	/* 
	string str12 = "cs2310 computer programming"; 
	string str13=" cs";
	int len=str12.length();
	int pos1=str12.find(" computer");
	str12=str12.insert(pos1,str13);
	//!这个插在哪里的索引pos1 是原来字符串从哪个字符开始往后移 pos1就是谁的索引
	cout<<"insert之后的字符串是"<<str12<<endl;
	int pos=str12.rfind("cs");
	str12=str12.erase(pos,str13.length());
	cout<<"erase擦除之后的字符串是"<<str12<<endl;
	 */
	

	/* 
	string str15 = "abcd@cityu.edu.hk";
	//todo 定位@所在的位置 然后只要这个位置减去前面的一个位置等于 前面那个位置到@的长度
	int index=str15.find("@");
	cout<<"@前面的字符串是："<<str15.substr(0,index)<<endl;
	 */


	
	string str16, str17("aab");
	str16 = "aac";
//	str16 = "aaa";
//	str16 = "aabc";
//	str16 = "aa";
//	str16 = "aab";
	cout << str16.compare(str17) << endl;
	

	return 0;
}
