#include <iostream>
using namespace std;

int main() {
	
	int num[3] = {40,50,60}; // 一个数组
	int *p = num; //此时的 指针p就是第一个元素的地址

	cout << (long)p << endl; //转化成十进制
	cout << *p << endl;// 这里* 对指针取值 所以就是第一个元素的值
	cout << (long)num << endl; //还是第一个元素的指针	
	cout << endl;

	cout << *num << endl; //根据指针取值 第一个元素的值
	cout<<*(num+1)<<endl;
	cout<<*(num+2)<<endl;
	cout << endl;
    
	cout << (num == &num[0]) << endl; //True 对一个元素取指针 也就是num本身第一个元素的地址		
	cout << ((num+1) == &num[1]) << endl; //True 第二个元素的地址 以及第二个元素 然后取地址	
	cout << (*num == num[0]) << endl;	//True对第一个元素取值 num[0]第一个元素		
	cout << (*(num+1) == num[1]) << endl; //True *第二个元素取值 等于直接num[1]第二个元素		
	cout << (((*num)+1) == num[0]+1) << endl;//True 第一个元素取值加一41 等于 也是40+1 	
	cout << endl;
	
	cout << ((++p) == &num[1]) << endl;// True ++p 先自增再返回值 所以都是指向第二个元素的地址	
	cout << (*(p++) == num[1]) << endl; //!True 这个是因为上面已经增到第二个元素先返回他的值 然后再自增到第三个元素 另num[1]一个是第二个元素的值			
	cout << endl;
	
	p = num;//p回到第一个元素的地址
	cout << *(p++) << endl;	 //第一个元素的值40 先返回再自增		
	cout << *p << endl;	//上一个因为自增 所以这个*p是第二个元素的值50				
	
	return 0;
}



/* 
1.数组名num就是第一个元素的地址：num == &num[0] 为真

2.指针算术：num+1指向下一个元素，*(num+1)取值等于num[1]

3.前置++p：先自增再返回，p指向下一个元素

4.后置p++：先返回当前值再自增，*p++先取值再移动指针

5.连续操作注意：指针状态会改变，影响后续结果
*/