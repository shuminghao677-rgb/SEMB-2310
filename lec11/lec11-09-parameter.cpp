#include <iostream>
#include <string>
using namespace std;

template <typename T,typename U>
class DayOfYear{
    public:
        T month;
        U day;
        DayOfYear(T m,U d): month(m),day(d){}
};

template <typename T,typename U>
void print(const DayOfYear<T,U>& d){
    cout<<"Date:  "<<d.month<<" "<<d.day<<endl;
}

int main(){
    DayOfYear<string,int> d1("September",11);// emplicit specification
    print(d1);
    cout<<endl;
}

/*
1. 类模板 DayOfYear<T,U>：支持不同类型存储月份和日期

2. 构造函数：用初始化列表初始化 month 和 day

3. 全局函数模板 print：接收 DayOfYear 对象，打印日期

4. 显式指定：DayOfYear<string,int> d1("September",11) 必须指定模板参数

5. 输出结果：Date: September 11
*/