#include <iostream>
using namespace std;

class Dayofyear{
	private:
		int month;
		int day;
	public:
		Dayofyear() {
			month=1;
			day=1;
			cout<<"默认构造函数被调用"<<endl;
		}
		Dayofyear(int m,int d):month(m),day(d){
			cout<<"参数构造函数被调用"<<endl;
		}
		Dayofyear(const Dayofyear &d){ //引用传参
			month=d.month;
			day=d.day;
			cout<<"拷贝构造造函数被调用"<<endl;
		}
		void show(){ //member function 打印日期
			cout<<"日期是 "<<month<<" 月 "<<day<<" 日。"<<endl;
		}
	};
void f(Dayofyear d1){
	d1.show();//void是在public 里的成员函数
}

int main() {
	Dayofyear d;
	f(d);//因为d1写在 helper函数里 不需要再次在main里构建了
	Dayofyear d2(3,5);
	d2.show();
	cout<<endl;
	Dayofyear d3(d2);
	d3.show();
	d2.show();
	cout<<endl;
	f(d3);//把d3 数据赋值给d1 helper参数函数
	return 0;
}


/* 
1.默认构造函数：无参，初始化month=1, day=1

2.参数构造函数：有参，用初始化列表设置month和day

3.拷贝构造函数：const引用传参，用已有对象创建新对象

4.成员函数show()：打印日期信息

5.helper函数f()：传值调用触发拷贝构造，形参d1接收实参副本

6.main执行顺序：
   - 默认构造d
   - f(d)触发拷贝构造创建d1
   - 参数构造d2(3,5)
   - 拷贝构造d3(d2)
   - f(d3)再次触发拷贝构造
*/ 