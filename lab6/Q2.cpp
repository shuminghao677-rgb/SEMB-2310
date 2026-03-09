/* Input	Result
10
5 20 400
3 12 -65.3
5 11 -9.4
5 11 -2.8
10 31 200
6 2 -230.5
2 11 -67.3
5 25 -127.5
7 2 200
8 29 -67.3
Enter the number of the records:
Enter the contents of each records:
Sort according to the balance:
6 2 -230.5
5 25 -127.5
2 11 -67.3
8 29 -67.3
3 12 -65.3
5 11 -9.4
5 11 -2.8
10 31 200
7 2 200
5 20 400
Sort according to the time:
2 11 -67.3
3 12 -65.3
5 11 -9.4
5 11 -2.8
5 20 400
5 25 -127.5
6 2 -230.5
7 2 200
8 29 -67.3
10 31 200 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//todo 构建class Time
class Time{
    public:
        int month,day;
        double balance;
        Time():month(0),day(0),balance(0){} //默认构建函数
        Time(int m, int d, int b):month(m),day(d),balance(b){} //参数构建函数

};
//todo 两个全局sort函数返回的是true 在 sort(A,B,函数逻辑)这里就是当满足函数逻辑返回true的时候就保持顺序不变
bool sortBalance(const Time &a,const Time &b){//在全局helper函数这里 当参数与对象组同级是引用传参 如果高于对象组就是指针传参
    //*引用传参 const Time &a,const Time &b 
    //*指针传参 Clock *p
    if (a.balance<b.balance){ //sort函数是 else if结构 从来小于不取等
        return true;
    }else{
        return false;
    }
}

bool sortTime(const Time &a,const Time &b){
    if (a.month<b.month){ //*两个维度考虑的时候就是时间排序 这个最好背下来 同样小于不取等
        return true;
    }else if(a.month==b.month){
        if(a.day<b.day){
            return true;
        }else{
            return false;
        }
    }else{ //*最后else的部分容易被落下
        return false;
    }
}
//todo main entry 主函数
int main(){
    int N;
    cout<<"Enter the number of the records:"<<endl;
    cin>>N;
    Time recordes[N];
    cout<<"Enter the contents of each records:"<<endl;
    for(int i=0;i<N;i++){
        cin>>recordes[i].month>>recordes[i].day>>recordes[i].balance;

    }
    cout<<"Sort according to the balance:"<<endl;
    sort(recordes,recordes+N,sortBalance);
    for(int i=0;i<N;i++){
        cout<<recordes[i].month<<" "<<recordes[i].day<<" "<<recordes[i].balance<<endl;
    }
    cout<<"Sort according to the time:"<<endl;
     sort(recordes,recordes+N,sortTime);//*sort 结构(A,B,sort逻辑函数【返回的是bool】)
    for(int i=0;i<N;i++){
        cout<<recordes[i].month<<" "<<recordes[i].day<<" "<<recordes[i].balance<<endl;
    }
    return 0;
}