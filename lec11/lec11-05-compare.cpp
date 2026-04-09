#include <iostream>
using namespace std;

class DayofYear{
    public:
        int month;
        int day;
        DayofYear(int m,int d):month(m),day(d){}       
};

template <typename T>
bool isGreaterThan(const T& a,const T& b){// 只对a b值进行读取 不进行重新赋值和修改
    return a>b;
}

template <>//模版特化 因为通用模版不能直接处理自定义class里面的成员变量 所以只能模版特化 
//但是要求函数名是一样的 相当于如果不是 整数变量或者其他的double是 dayofyear的时候就用下面的那个函数
//相当于做一个补充的作用
bool isGreaterThan(const DayofYear& a, const DayofYear& b){
    if (a.month>b.month){
        return true;
    }else if (a.month<b.month){
        return false;
    }else{
        return a.day>b.day;
    }
}

int main(){
    int m1,d1;
    cout<<"please enter the date of the first day!"<<endl;
    cout<<endl;
    cin>>m1>>d1;
    DayofYear D1(m1,d1);

    int m2,d2;
    cout<<"please enter the date of the second day!"<<endl;
    cout<<endl;
    cin>>m2>>d2;
    DayofYear D2(m2,d2);

    cout<<"is the first day greater than the second day?"<<isGreaterThan(D1,D2)<<endl;
    return 0;
}



/*
1. 类模板：DayofYear 用初始化列表初始化 month 和 day

2. 通用模板：isGreaterThan 用 > 运算符比较，适用于 int、double、char 等基本类型

3. 模板特化：专门为 DayofYear 类型定制比较逻辑（比较月、日）

4. 特化语法：template <> 表示特化，函数名与通用模板相同

5. 调用规则：参数为 DayofYear 时自动选择特化版本，其他类型用通用模板

6. 程序流程：用户输入两个日期 → 创建 DayofYear 对象 → 调用特化版本比较 → 输出结果
*/