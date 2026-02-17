#include <iostream>
#include <cmath>
// * three types of function in cpp liberary
// #include <cmath> 关于数学
//#include <string> 关于字符串
//#include <iostream> 关于输入输出
using namespace std;

void main() {
	double area,side;
	cout<<"Enter the area of a square"<<endl;
	cin>>area;
	side=sqrt(area);//用了数学 所以#include <cmath>
	cout<<"The square has the perimeter: "<<4*side<<endl;
}
