#include <iostream>
using namespace std;

// int main() {
// 	int n,m;
// 	cin>>n;
// 	cin>>m;
// 	for(int i=0;i<n;i++){
// 		for (int j=0;j<m;j++){
// 			cout<<(i+1)*(j+1)<< "\t";//这里没有endl 就保持自动不换行 //但是要添加制表符
// 		}
// 		cout<<endl;//给每个外层循环加换行
// 	}
// 	return 0;
// }

int main(){
	int l;
	cout<<"Enter diagonal length:";
	cin>>l;
	for (int i=0;i<l;i++){
		cout<<string(i,' ')<<"x"<<endl;
	}
    return 0;
}