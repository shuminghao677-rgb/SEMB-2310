#include <iostream>
#include <string>
using namespace std;

template <typename T>
T myadd(T a,T b){
    return a+b;
}
//字符串模版
/* template <typename T>
T myadd (T a,T b){
    return a+b;
} */

int main() {
    cout<<"使用模版做整数加法"<<endl;
    cout<<"结果是:  "<<myadd<int>(1,2)<<endl;
    cout<<"使用模版做小数加法"<<endl;
    cout<<"结果是:  "<<myadd<double>(1.1,2.2)<<endl;
    cout<<"使用模版做字符加法"<<endl;
    cout<<"结果是:  "<<myadd<char>('1','2')<<endl;//这里是 ASCII加法
    cout<<"使用模版做字符串加法"<<endl;
    //两种调用方式 可以 myadd<int>(1,2)  也可以直接 myadd(1,2) 
    cout<<"结果是:  "<<myadd(string("my"),string("add"))<<endl;
    cout<<"结果是:  "<<myadd<string>("my","add")<<endl;
    return 0;
}




/*
1. 模板(Template)：typename T 表示通用类型，编译时根据参数生成具体函数

2. 类型推导：myadd(1,2) 自动推导为 int，myadd(1.1,2.2) 推导为 double

3. 显式指定：myadd<int>(1,2) 强制指定类型，参数会隐式转换

4. char 加法：'1'(ASCII 49) + '2'(ASCII 50) = 99 → 输出字符 'c'

5. string 加法：必须用 string 类型，字符串字面量"my"是 const char*，不能直接加法

6. 两种正确写法：
   - myadd(string("my"), string("add"))  // 自动推导为 string
   - myadd<string>("my", "add")          // 显式指定 + 隐式转换
*/