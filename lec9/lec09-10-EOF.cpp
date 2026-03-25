#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("input.txt");

	/* 等价写法
	ifstream fin;
	fin.open("input.txt"); */
	ofstream fout("output.txt");
	int x;
	while(fin>>x){
		fout<<x<<" ";
	}
	fin.close();
	fout.close();
	return 0;
}

/*
1. ifstream fin("input.txt")：声明输入文件流并打开文件（读）

2. while(fin >> x)：循环从fin读取整数到x，读到末尾自动退出

3. ofstream fout("output.txt")：声明输出文件流并打开文件（写）

4. fout << x：将读取到的x写入输出文件

5. fin.close()：关闭输入文件

6. fout.close()：关闭输出文件
*/