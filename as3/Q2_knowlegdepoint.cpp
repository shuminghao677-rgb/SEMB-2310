#include <iostream>
using namespace std;

template <typename T>
class MyArray{
    private:
        T* pAddress;
        int mSize;
        int mCapacity;
    public:
        MyArray(int mc){
            mCapacity=mc;
            pAddress=new T[mc];
            mSize=0;
        }
        ~MyArray(){
            delete[] pAddress;//因为这里是删除的数组所以是 delete[]
            pAddress=nullptr;
        }
        MyArray(const MyArray& other){ //一个深拷贝函数 先重新分配内存 然后把数组里的元素一个一个复制过来
            this->mSize=other.mSize;
            this->mCapacity=other.mCapacity;
            this->pAddress=new T[this->mCapacity];
            for(int i=0;i<other.mSize;i++){
                this->pAddress[i]=other.pAddress[i];
            }
        }
        MyArray& operator=(const MyArray& other){ //目的是提高效率所以返回的是myarray这个对象本身不是副本 所以是 MyArray&
            if(this==&other){ //因为this是指针 所以 比较的时候也要和 other这个对象的指针比较 所以是&other
                return *this;//最后因为是要返回对象 不是指针 所以是 return * this;
            }else{
                this->mSize=other.mSize;
                this->mCapacity=other.mCapacity;
                delete[] this->pAddress;//overload operator=相比拷贝函数是原来已有对象所以要先释放内存 在拷贝
                pAddress=new T[this->mCapacity];
                for(int i=0;i<other.mSize;i++){
                this->pAddress[i]=other.pAddress[i];
                }
                return *this;
            }  
        }
};

