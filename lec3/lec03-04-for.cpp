#include <iostream>
using namespace std;
 
// 一个关于while 输入的计算sum值的函数
// int main() {

// 	int sum = 0;
// 	int num;
// 	while (cin>>num && num!=-1){
// 		sum+=num;
// 	}
// 	cout << "sum is: " << sum << endl;

// 	return 0;
// }

//用创建数组 for 循环实现
int main(){
    vector<int>arr1;
    int num;

    while(cin>>num && num!=-1){
        arr1.push_back(num);
    }

    int sum=0;
    for (int i=0;i<arr1.size();i++){
        sum+=arr1[i];
    }
    cout<<"最后的数组是：  "<<endl;
    for (int j=0;j<arr1.size();j++){
        cout<<arr1[j]<<" ";
    }
    cout<<",和是"<<sum<<endl;
    return 0;
}


