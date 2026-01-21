#include <iostream>
using namespace std;

// int main() {
// 	int a1=3;
// 	int a2=4;
// 	cout<<endl<<"the final anwser is:   "<<a1+a2<<endl;
// 	return 0;
// }

//7

// int main() {
// 	int k=0;
// 	int i=1+(k++);
// 	cout<<endl<<"the final anwser is:   "<<i<<endl;
// 	return 0;
// }

//1

// int main() {
// 	int k=10;
// 	int y=(k++)+1;
// 	cout<<endl<<"the final anwser is:   "<<y<<endl;
// 	return 0;
// }

//11

// int main() {
// 	int k=10;
// 	int y=(++k)+1;
// 	cout<<endl<<"the final anwser is:   "<<y<<endl;
// 	return 0;
// }

//12

// int main(){
// 	int a=5;
// 	int b=2;
// 	cout<<a/b<<endl;
// }

//2

// int main(){
// 	int a=5;
// 	int b=2;
// 	cout<<a%b<<endl;
// }

//1

// int main(){
// 	int b=2,c=1;
// 	cout<<b+++c<<endl;
// 	// 编译器会理解成（b++）+c
// 	return 0;
// }
//3

// int main(){
// 	int a=3,b=2;
// 	int tmp;
// 	cout<<a<<endl;
// 	cout<<b<<endl;
// 	tmp=a;
// 	a=b;
// 	b=tmp;
// 	cout<<a<<endl;
// 	cout<<b<<endl;
// 	return 0;
// }
// 3
// 2
// 2
// 3

// int main(){
// 	int a=0;
// 	int b=1;
// 	bool result=a&&b;
// 	cout<<result<<endl;
// 	return 0;
// }

//0

// int main(){
// 	int a=0;
// 	int b=1;
// 	bool result=a>1||a<1;
// 	cout<<result<<endl;
// 	return 0;
// }
//1

// int main(){
// 	int score;
// 	cout<<"enter your scores here:   "<<endl;
// 	cin>>score;
// 	if (score>=90)
// 		cout<<"you got an A range";
// 	cout<<"your grade is under A range"<<endl;
// 	return 0;
// }

// int main(){
// 	int score;
// 	cout<<"enter your scores here:   "<<endl;
// 	cin>>score;
// 	if (score>=90){
// 		cout<<"you got an A range";
// 		cout<<"congrats!";
// 	}
// 	else{
// 		cout<<"your grade is under A range"<<endl;
// 		cout<<"dont be worry";
// 	}
// 	return 0;
// }

int main(){
	int score;
	cout<<"enter your scores here:   "<<endl;
	cin>>score;
	if (score>=90){
		cout<<"you got an A range";
		cout<<"congrats!";
	}else if (score<90 && score>=80){
		cout<<"you got an B range";
	}else if (score<80 && score>=70){
		cout<<"you got an C range";
	}else if (score<70 && score>=60){
		cout<<"you got an D range";
	}else{
		cout<<"you fail this course";
	}
	return 0;
}
//这里multiple condition 括号里面必须是一个 logical expression


