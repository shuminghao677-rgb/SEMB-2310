#include <iostream>
#include <cmath>
using namespace std;

struct MyComplex{ 
//对于 struct 和 class的区别就是更开放 不需要标注 public protected 和 private 其他基本一样
    double Real;
    double Imaginary;
//对于struct 也要添加构造函数 因为需要有参数构造函数 所以补充一个默认构造函数
    MyComplex(){
        Real=0;
        Imaginary=0;
    }
    MyComplex(double r,double i){
        Real=r;
        Imaginary=i;
    }
};

class Calculator{
    protected:
        MyComplex num1;
        MyComplex num2;
    public:
        int flag=0;
        void set(MyComplex n1,MyComplex n2){
            num1=n1;
            num2=n2;
        }
        virtual MyComplex getResult()=0;
        virtual ~Calculator(){}
        //这是一个虚函数 最后用不同的运算指针 调用getResult得到不同的运算逻辑结果
};
class AdditionCal:public Calculator{
    public:
        MyComplex getResult()override{
            double Real_part=num1.Real+num2.Real;
            double Imaginary_part=num1.Imaginary+num2.Imaginary;
            return MyComplex(Real_part,Imaginary_part);
        }
};

class SubtractionCal:public Calculator{
    public:
        MyComplex getResult()override{
            double Real_part=num1.Real-num2.Real;
            double Imaginary_part=num1.Imaginary-num2.Imaginary;
            return MyComplex(Real_part,Imaginary_part);
        
        }
};

class MultiplyCal:public Calculator{
    public:
        MyComplex getResult()override{
            double a=num1.Real;
            double b=num1.Imaginary;
            double c=num2.Real;
            double d=num2.Imaginary;
            double Real_part=a*c-b*d;
            double Imaginary_part=a*d+b*c;
            return MyComplex(Real_part,Imaginary_part);
        }
};

class DivisionCal:public Calculator{
    public:
        MyComplex getResult()override{
            double a=num1.Real;
            double b=num1.Imaginary;
            double c=num2.Real;
            double d=num2.Imaginary;
            double dominator=pow(c,2)+pow(d,2);
            if (dominator==0){
                flag=1;
                return MyComplex(0,0);  
            }else{
                double Real_part=(a*c+b*d)/dominator;
                double Imaginary_part=(b*c-a*d)/dominator;
                return MyComplex(Real_part,Imaginary_part);
            }
        }
};
ostream& operator<<(ostream&os,const MyComplex&mc){
    if (mc.Real==0){
        if(mc.Imaginary==0){
            os<<0;
        }else{
            os<<mc.Imaginary<<"i";
        }
    }else{
        if (mc.Imaginary>0){
            os<<mc.Real<<"+"<<mc.Imaginary<<"i";
        }else if(mc.Imaginary<0){
            os<<mc.Real<<mc.Imaginary<<"i";
        }else{
            os<<mc.Real;
        }
    }
    return os;
}

int main(){
    double op1r,op1i;
    cout<<"Input the first operand:"<<endl;
    cin>>op1r>>op1i;
    double op2r,op2i;
    cout<<"Input the second operand:"<<endl;
    cin>>op2r>>op2i;
    MyComplex mc1(op1r,op1i);
    MyComplex mc2(op2r,op2i);
    Calculator* ptr1=new AdditionCal();
    ptr1->set(mc1,mc2);
    MyComplex result1=ptr1->getResult();
    cout<<"The result of "<<"("<<mc1<<")"<<"+"<<"("<<mc2<<")"<<" is "<<result1<<endl;
    delete ptr1;
    ptr1=nullptr;
    Calculator* ptr2=new SubtractionCal();
    ptr2->set(mc1,mc2);
    MyComplex result2=ptr2->getResult();
    cout<<"The result of "<<"("<<mc1<<")"<<"-"<<"("<<mc2<<")"<<" is "<<result2<<endl;
    delete ptr2;
    ptr2=nullptr;
    Calculator* ptr3=new MultiplyCal();
    ptr3->set(mc1,mc2);
    MyComplex result3=ptr3->getResult();
    cout<<"The result of "<<"("<<mc1<<")"<<"*"<<"("<<mc2<<")"<<" is "<<result3<<endl;
    delete ptr3;
    ptr3=nullptr;
    Calculator* ptr4=new DivisionCal();
    ptr4->set(mc1,mc2);
    MyComplex result4=ptr4->getResult();
    if(ptr4->flag==1){
        cout<<"Error: Division by zero!"<<endl;
    }
    cout<<"The result of "<<"("<<mc1<<")"<<"/"<<"("<<mc2<<")"<<" is "<<result4<<endl;
    delete ptr4;
    ptr4=nullptr;
    return 0;
}
