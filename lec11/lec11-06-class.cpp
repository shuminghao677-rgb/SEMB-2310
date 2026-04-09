#include <iostream>
using namespace std;

template <typename T>
class myCon{
    private:
        T* ptr;
        int size;
    public:
        myCon(T arr[],int s){
            size=s;
            ptr=new T[s];
            for (int i=0;i<s;i++){
                ptr[i]=arr[i];//因为ptr是数组指针 所以可以直接用ptr[i]指向数组的第i个元素
                // 等效于 *（ptr+i）
            }
        }
        ~myCon(){
            delete[] ptr;
            ptr=nullptr;
        }
        void print();//先声明 之后组外定义成员函数
        friend ostream& operator<<(ostream &cout,myCon<T> &c){ //相当于还在定义对象 没有明确包含是什么类型变量数组 
            for(int i=0;i<c.size;i++){
                cout<<c.ptr[i]<<"  ";
            }
            return cout;
        }
};
template <typename T>//因为是组外接着定义成员函数 print所以需要重新声明函数print
void myCon<T>::print(){
    for (int i=0;i<size;i++){
        cout<<ptr[i]<<"  ";
    }
}

int main() {

    int arr_int[] = {3, 8, 7, 9, 0, 2, 4, 1, 5, 6};
    int s = sizeof(arr_int) / sizeof(arr_int[0]);
    myCon c1(arr_int,s);
    cout<<c1<<endl;
    cout<<endl;

    char arr_char[] = {'C', 'S', '2', '3', '1', '0'};
    s = sizeof(arr_char) / sizeof(arr_char[0]);
    myCon c2(arr_char,s);
    c2.print();
    cout<<endl;
    cout<<endl;

    return 0;
}


/*
1. 类模板 myCon<T>：可存储任意类型(T)的动态数组

2. 构造函数：分配堆内存(T* ptr = new T[s])，拷贝数组元素(ptr[i]=arr[i])

3. 析构函数：释放堆内存(delete[] ptr)，防止内存泄漏

4. 两种输出方式：
   - 友元函数 operator<<：支持 cout << 对象，简洁优雅
   - 成员函数 print()：传统方式，对象.函数名()调用

5. 类外定义成员函数：必须重新写 template <typename T> 和 myCon<T>::

6. 类型推导(C++17)：myCon c1(arr_int,s) 自动推导 T = int，myCon c2(arr_char,s) 推导 T = char
*/