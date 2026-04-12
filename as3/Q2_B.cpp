#include <iostream>
using namespace std;

class MyClassInt{
    private:
        int val;
    public:
        MyClassInt(){
            val=0;
        }
        MyClassInt(int v){
            val=v;
        }
        MyClassInt& operator=(const MyClassInt& other){
            this->val=other.val;
            return *this;
        }
        bool operator>(const MyClassInt& other) const {
            return this->val>other.val;
        }
        friend ostream& operator<<(ostream& os,const MyClassInt& mc);

};
ostream& operator<<(ostream& os,const MyClassInt& mc){
    os<<mc.val;
    return os;
}