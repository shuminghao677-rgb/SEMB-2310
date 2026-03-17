#include <iostream>
using namespace std;
class Time{
    public:
        int month;
        int day;
        double balance;
};

int main(){
    int N;
    cout<<"Enter the number of the records:"<<endl;
    cin>>N;
    cout<<"Enter the contents of each records:"<<endl;
    Time times[N];
    for(int i=0;i<N;i++){
        cin>>times[i].month>>times[i].day>>times[i].balance;
    }
    cout<<"Sort according to the balance:"<<endl;
    for(int i=0;i<N-1;i++){
        for(int j=N-1;i>j;j--){
            if (times[j-1].balance>times[j].balance){
                Time tmp;
                tmp=times[j-1];
                times[j-1]=times[j];
                times[j]=tmp;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<times[i].month<<" "<<times[i].day<<" "<<times[i].balance<<endl;
    }
    cout<<"Sort according to the time:"<<endl;
    for(int i=0;i<N-1;i++){
        for(int j=N-1;i>j;j--){
            if (times[j-1].month>times[j].month){
                Time tmp;
                tmp=times[j-1];
                times[j-1]=times[j];
                times[j]=tmp;
            } else if (times[j-1].month==times[j].month){
                if (times[j-1].day>times[j].day){
                    Time tmp;
                    tmp=times[j-1];
                    times[j-1]=times[j];
                    times[j]=tmp;
                } else {
                    continue;
                }
            } else{
                continue;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<times[i].month<<" "<<times[i].day<<" "<<times[i].balance<<endl;
    }
    return 0;
}