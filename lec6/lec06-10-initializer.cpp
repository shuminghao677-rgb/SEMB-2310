#include <iostream>
using namespace std;
#include <string>

class DayOfYear { //todo class 构造函数
	public:
		//todo 对全部参数进行初始化赋值
		DayOfYear(int d,int m,string f):day(d), month(m),flag(f){ 
			if (d%2!=0){
				flag="odd date";
			} else{
				flag="even date";
			}
		} //todo 复杂条件语句赋值 写在大括号里面
		int day;
		int month;
		string flag;
		//* day month flag 是class里面的member variables 有点像Struts里的attribute
};

int main() {
	DayOfYear today(25,2,"date"); //todo instantiating an object 同时call函数并且初始化
	cout<<"today is"<<today.month<<"月"<<today.day<<"号是"<<today.flag<<endl;
	return 0;
}
