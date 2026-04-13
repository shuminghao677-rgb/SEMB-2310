#include <iostream>
#include <iomanip>
using namespace std;

class Calculator{
    protected:
        int num1;
        int num2;
    public:
        int flag=0;
        void set(int n1,int n2){
            num1=n1;
            num2=n2;
        }
        virtual double getResult()=0;
        virtual ~Calculator(){};
};

class AdditionCal:public Calculator{
    public:
        double getResult() override {
            return num1+num2;
        }
};
class SubtractionCal:public Calculator{
    public:
        double getResult() override{
            return num1-num2;
        }
};
class MultiplyCal:public Calculator{
    public:
        double getResult() override{
            return num1*num2;
        }
};
class DivisionCal:public Calculator{
    public:
        double getResult() override{
            if(num2==0){
                cout<<"The divisor can't be 0."<<endl;
                flag=1;
                return 0.0;
            }else{
                return (double)num1/num2;
            }
        }
};

int main(){
    int n1,n2;
    cout<<"Input the first operand: "<<endl;
    cin>>n1;
    cout<<"Input the second operand: "<<endl;
    cin>>n2;
    if (n2<0){
        Calculator* cptr1=new AdditionCal();
        cptr1->set(n1,n2);
        cout<<"The result of "<<n1<<"+("<<n2<<") is "<<cptr1->getResult()<<endl;
        delete cptr1;
        Calculator* cptr2=new SubtractionCal();
        cptr2->set(n1,n2);
        cout<<"The result of "<<n1<<"-("<<n2<<") is "<<cptr2->getResult()<<endl;
        delete cptr2;
        Calculator* cptr3=new MultiplyCal();
        cptr3->set(n1,n2);
        cout<<"The result of "<<n1<<"*("<<n2<<") is "<<cptr3->getResult()<<endl;
        delete cptr3;
        Calculator* cptr4=new DivisionCal();
        cptr4->set(n1,n2);
        cout<<fixed<<setprecision(2);
        double result4=cptr4->getResult();
        if (cptr4->flag==1){
        }else{
            cout<<"The result of "<<n1<<"/("<<n2<<") is "<<result4<<endl;
        }
        delete cptr4;
    }else {
        Calculator* cptr1=new AdditionCal();
        cptr1->set(n1,n2);
        cout<<"The result of "<<n1<<"+"<<n2<<" is "<<cptr1->getResult()<<endl;
        delete cptr1;
        Calculator* cptr2=new SubtractionCal();
        cptr2->set(n1,n2);
        cout<<"The result of "<<n1<<"-"<<n2<<" is "<<cptr2->getResult()<<endl;
        delete cptr2;
        Calculator* cptr3=new MultiplyCal();
        cptr3->set(n1,n2);
        cout<<"The result of "<<n1<<"*"<<n2<<" is "<<cptr3->getResult()<<endl;
        delete cptr3;
        Calculator* cptr4=new DivisionCal();
        cptr4->set(n1,n2);
        cout<<fixed<<setprecision(2);
        double result4=cptr4->getResult();
        if (cptr4->flag==1){
        }else{
            cout<<"The result of "<<n1<<"/"<<n2<<" is "<<result4<<endl;
        }
        delete cptr4;
    }
    return 0;
}