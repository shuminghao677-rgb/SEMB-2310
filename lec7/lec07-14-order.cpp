#include <iostream>
using namespace std;

class Base{
	public:
		Base(){cout<<"Base-contructor"<<endl;};
		~Base(){cout<<"Base-destructor"<<endl;};
};
class Child : public Base{
	public:
		Child(){cout<<"Child-contructor"<<endl;};
		~Child(){cout<<"Child-destructor"<<endl;};
};

int main(){
	Child c;
}

/* 
1.构造顺序：先父类后子类（先有基础部分，再扩展）

2.析构顺序：先子类后父类（先清理自己，再清理基础）

3.输出验证：
   Base-contructor  ← 先构造父类
   Child-contructor ← 再构造子类
   Child-destructor ← 先析构子类
   Base-destructor  ← 再析构父类

4.原因：子类对象包含父类部分，像盖房子先打地基（父类）再盖上层（子类），拆的时候先拆上层再拆地基
*/