#include <iostream>
using namespace std;

class Machine{
    public:
        virtual void start(){
            cout<<"父对象 Machine start函数"<<endl;
        }
};
class Car:public Machine{
    public:
        void start(){
            cout<<"public继承Machine Car的start函数"<<endl;
        }
};

class Trunk:public Machine{
    public:
        void start(){
            cout<<"public继承Machine Trunk的start函数"<<endl;
        }
};

class Bus:public Machine{
    public:
        void start(){
            cout<<"public继承Car Bus的start"<<endl;
        }
};

void launch(Machine *mptr){
    mptr->start();
    cout<<endl;
}


int main() {
    Machine *mptr[4];//建立指针数组

    Machine m;
    Car c;
    Trunk t;
    Bus b;

    mptr[0]=&m;
    mptr[1]=&c;
    mptr[2]=&t;
    mptr[3]=&b;

    launch(mptr[0]);
    launch(mptr[1]);
    launch(mptr[2]);
    launch(mptr[3]);

	return 0;
}

/*
1. 多态数组：Machine* 指针数组可以存储不同派生类对象的地址

2. 虚函数：start()在基类中声明为virtual，实现动态绑定

3. launch函数：接收基类指针，根据实际对象类型调用对应的start()

4. 输出结果：
   - mptr[0]指向Machine对象 → 调用Machine::start()
   - mptr[1]指向Car对象 → 调用Car::start()
   - mptr[2]指向Trunk对象 → 调用Trunk::start()
   - mptr[3]指向Bus对象 → 调用Bus::start()
*/