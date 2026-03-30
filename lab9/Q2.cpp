#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Candy{
    private:
        string name;
        double price;
        int amount;
    public:
        Candy(){ //设计默认构造函数
            name="";
            price=0.0;
            amount=0;
        }
        Candy(string n,double p,int a){
            name=n;
            price=p;
            amount=a;
        }
        Candy operator+(const Candy& OtherCandy){
            Candy SumCandy;
            SumCandy.name=this->name+"-"+OtherCandy.name;
            SumCandy.price=(this->price+OtherCandy.price)/2.0;//这里是计算平均值
            SumCandy.amount=this->amount+OtherCandy.amount;
            return SumCandy;
        }
        //友元函数声明写在class 里面 友元函数实现写在class外面 
        friend ostream& operator<<(ostream& os,const Candy&c);
        //friend 友元函数 ostream& 输出流引用 operator 运算符<<写的符号 以及两个参数分别是输出流引用和 打印对象的引用

        friend ostream& operator<<(ostream& os,const Candy&c); //友元函数声明
        
};
ostream& operator<<(ostream& os,const Candy& c){
    os<<"name-"<<c.name<<"; price-"<<c.price<<"; amount-"<<c.amount<<endl;
    return os;
}
ostream& operator<<(ostream& os,const Candy&c){
            os<<"name-"<<c.name<<"; price-"<<c.price<<"; amount-"<<c.amount<<endl;
            return os;//友元函数类外实现 函数最后要记得返回os  相当于 设计对象的打印在主函数
        }

int main(){
    string n1,n2;
    double p1,p2;
    int a1,a2;
    cout<<"Enter name: "<<endl;
    cin>>n1;
    cout<<"Enter price: "<<endl;
    cin>>p1;
    cout<<"Enter amount: "<<endl;
    cin>>a1;
    cout<<"Enter name: "<<endl;
    cin>>n2;
    cout<<"Enter price: "<<endl;
    cin>>p2;
    cout<<"Enter amount: "<<endl;
    cin>>a2;
    Candy c1(n1,p1,a1);
    Candy c2(n2,p2,a2);
    Candy c3=c1+c2;
    cout<<"c3: "<<c3<<endl;
    return 0;
}
