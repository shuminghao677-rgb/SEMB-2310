#include <iostream>
using namespace std;

int *f(){
  int n=10;
  int *ptr=&n;
  return ptr;
}

int *f1(){
  int n=10;
  int *ptr1=new int(n);
  return ptr1;
}

int *f2(){
  int static n=10;
  int *ptr2= &n;
  return ptr2;
}

int main(){

  int *ptr=f();
  cout<<"ptr指针指向的值是"<<*ptr<<endl;
  //这里本来应该指向的是n 但实际输出是1 【因为f函数结束后n被释放 所以出现了野指针 wild pointer】

  cout<<endl;
  cout<<endl;

  int *ptr1=f1();
  cout<<"ptr1指针指向的值是"<<*ptr1<<endl;
  delete ptr1;
  ptr1=nullptr;
  //带new的是堆内存 动态分配 【int *ptr1=new int(n);这一步是在堆上分配内存】

  cout<<endl;
  cout<<endl;

  int *ptr2=f2();
  cout<<"ptr2指针指向的值是"<<*ptr2<<endl;
  //静态变量 【int static n=10;这一步相当于n不会f2结束就释放 而是会等到程序结束后才释放也避免野指针】

  return 0;

}

/* 
1.f()返回局部变量地址：n在栈上，函数结束释放，ptr变成野指针，输出结果不可预测（如1或乱码）

2.f1()用new动态分配：在堆上分配内存，函数结束不释放，可以安全返回，但必须用delete手动释放，避免内存泄漏

3.f2()用静态变量：static n在静态区，程序结束才释放，可以安全返回，不需要delete

4.delete后置nullptr是好习惯：避免悬挂指针（指向已释放内存的指针） 

//* delete ptr1;
//* ptr1=nullptr;

*/



