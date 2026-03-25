#include <iostream>
using namespace std;
class Device{
    private:
        int price;
    public:
        int getPrice(){
            return price;
        }
        Device(int price){
            this->price=price;
        }
        void print(){
            cout<<"被继承里Device 的价格是:  "<<getPrice()<<endl;
        }
};

class Phone:public Device{
    public:
        Phone(int price):Device(price){};
        void watch(){
            cout<<"继承里Phone的价格是:  "<<getPrice()<<endl;
        }
};
int main() {
    Phone p1(1300);
    p1.print();
    p1.watch();
    return 0;
}


/*
1. 继承关系：Phone公有继承Device

2. 构造函数传递：Phone(int price) : Device(price) 将参数传给基类构造函数

3. 访问基类成员：Phone通过继承的getPrice()访问基类private成员price

4. 执行流程：创建Phone对象 → 先调用Device构造函数初始化price → 再初始化Phone部分
*/