#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout<<setfill('*');//空的字符 用*来填充
	cout<<setw(5);//五位的一个字符 右边对齐
	cout<<3.14<<endl;
	return 0;
}


int main(){
	cout.width(5);
	cout<<3.14<<endl;
	return 0;
}//#include <iomanip> 里的 setw()等效于cout.width(5)

int main(){
	cout<<setiosflags(ios::left);//变成左对齐
	cout<<setw(5);
	cout<<setfill('*');
	cout<<34<<endl;
	return 0;
}
