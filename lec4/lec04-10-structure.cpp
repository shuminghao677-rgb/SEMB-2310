#include <iostream>
using namespace std;

int main(){
	struct Course{ //创建结构体 struct 类型 Course 名字 里面包含一个整数 一个double相当于两个属性
	int course_id; 
	double score;
};

struct Course courses[3]={ //构建一个Course结构体组 叫courses size是3 然后对他进行统一赋值{{},{},{}}
	{1111,70},{2222,80},{3333,90}
};

for(int i=0;i<(sizeof(courses)/(sizeof(Course)));i++){ //循环输出 长度用sizeof结构组 除以sizeof单一结构体

	cout<<endl;
	cout<<courses[i].course_id<<"  :  "<<courses[i].score<<endl; //cout 时候要选中具体结构体组里的第几项的什么属性
	
}
return 0;
}
