#include <iostream>
#include <fstream> 
using namespace std;

int main() {
	int a, b, c;
	ifstream fin; //input file stream 输入文件流 从文件里读取数据 fin输入文件对象是fin
	fin.open("input.txt");//打开文件 input.txt
	fin>>a>>b>>c;//从文件中读取 a b c
	cout<<a<<" "<<b<<" "<<c<<" "<<endl;

	fin.close();//再把文件关上
	return 0;
}


/*
1. ifstream：输入文件流（Input File Stream），从文件读取数据

2. ofstream：输出文件流（Output File Stream），向文件写入数据

3. fstream：文件流（File Stream），可读可写

4. fin：文件输入对象变量名，通过open()打开文件，>>读取数据

5. 操作流程：创建对象 → open() → 读取/写入 → close()
*/
