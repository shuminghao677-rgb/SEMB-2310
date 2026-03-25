#include <iostream>
#include <fstream>
using namespace std;

const int BUF_SIZE = 512;

int main() {

	ifstream fin;//声明输入文件

	fin.open("/Users/fanxinyun2/Documents/c++算法冲刺/SemB-2310/CMakeLists.txt");//打开输入文件

	if (fin.fail()) {//如果输入文件打开时失败 报错
		cout << "open failed!" << endl;
		exit(1);//程序异常退出 exit(0)程序正常退出
	}
	char bur[BUF_SIZE];//提前写好bur的字符数组
	while(fin.getline(bur,BUF_SIZE)){ //while getline 成功打印每一行
		cout<<bur<<endl;//每一行单独输出
	}
	fin.close();//关闭fin 输入文件
	return 0;
}

/*
1. ifstream fin：声明输入文件流对象

2. fin.open(路径)：打开指定路径的文件

3. fin.fail()：检查文件是否成功打开，失败则打印错误并exit(1)终止程序

4. exit(1)：程序异常退出（返回非0值给操作系统）；exit(0)表示正常退出

5. char bur[BUF_SIZE]：字符数组缓冲区，存储每行内容

6. fin.getline(bur, BUF_SIZE)：读取一行（最多BUF_SIZE-1个字符），遇到换行符停止并丢弃\n

7. while循环：每次读取一行，直到文件末尾自动结束

8. cout << bur << endl：输出每行内容并换行

9. fin.close()：关闭文件，释放资源
*/