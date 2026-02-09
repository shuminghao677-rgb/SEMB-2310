#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

const int N = 10;

struct Date {
    int day;
    int month;
    int year;
};

struct Order {
    int orderID;
    double price;
    Date date;
};

struct Restaurant {
    Order orders[N];
    int num;
};

void listOptions() {
    cout<<"0: Exit"<<endl;
    cout<<"1: Add"<<endl;
    cout<<"2: Show"<<endl;
    cout<<"3: Delete"<<endl;
    cout<<"4: Sort"<<endl;
    
}

void add(Restaurant *p) {
    cout<<"Input OrderID:"<<endl;
    cout<<"Input Price:"<<endl;
    cout<<"Input Order Date (dd mm yyyy):"<<endl;
    cout<<endl;
    if (p->num>=N){
        cout<<"Order list is full."<<endl;
    } else{
        cin>>p->orders[p->num].orderID;
        cin>>p->orders[p->num].price;
        cin>>p->orders[p->num].date.day>>p->orders[p->num].date.month>>p->orders[p->num].date.year;
        p->num++;
    }
}

void show(Restaurant *p) {
    cout<<setprecision(2);
    cout<<fixed;
    if(p->num==0){
        cout<<"no orders"<<endl;
    } else{
        for (int i=0;i<p->num;i++){
            string s=to_string(p->orders[i].orderID);
            if ((int)s.length()==1){
                s="00"+s;
            } else if((int)s.length()==2){
                s="0"+s;
            }else{
                s=s;
            }
            cout<<s<<"     "<<p->orders[i].price<<"   "<<p->orders[i].date.day<<'-'<<p->orders[i].date.month<<'-'<<p->orders[i].date.year<<endl;
        }
        }
    cout<<endl;
    }
    

void del(Restaurant *p) {
    int id;
    cout<<"Enter the orderID to be deleted"<<endl;
    cin>>id;
    int index=-1;
    for(int i=0;i<p->num;i++){
        if(p->orders[i].orderID==id){
            index=i;
            break;
        } else{
            index=index;
        }
    }
    if (index==-1){
        cout<<"The orderID cannot be found"<<endl;
    } else{
        for(int j=index;j<p->num-1;j++){
            p->orders[j]= p->orders[j+1];
        }
        p->num--;
    }
    cout<<endl;
}

void sort_id(Restaurant *p) {
    for (int i=0;i<p->num-1;i++){
        for (int j=p->num-1;j>i;j--){
            if (p->orders[j].orderID<p->orders[j-1].orderID){
                Order tmp;
                tmp=p->orders[j];
                p->orders[j]=p->orders[j-1];
                p->orders[j-1]=tmp;
            }
        }
    }
}

void sort_date(Restaurant *p) {
    for (int i=0;i<p->num-1;i++){
        for (int j=p->num-1;j>i;j--){
            Date date1=p->orders[j-1].date;
            Date date2=p->orders[j].date;
            int swap=0;
            if (date1.year>date2.year){
                swap=1;
            } else if(date1.year==date2.year){
                if (date1.month>date2.month){
                    swap=1;
                } else if(date1.month==date2.month){
                    if (date1.day>date2.day){
                        swap=1;
                    } else if (date1.day==date2.day){
                        if (p->orders[j-1].price<p->orders[j].price){
                            swap=1;
                        } else{
                            swap=0;
                        }
                        }
                }
            }
            if (swap==1){
                Order tmp;
                tmp=p->orders[j];
                p->orders[j]=p->orders[j-1];
                p->orders[j-1]=tmp;
            }
        }
    }
    
}

void sort(Restaurant *p) {
    cout<<"1: Sort by orderID"<<endl;
    cout<<"2: Sort by date"<<endl;
    cout<<endl;
    int n;
    cin>>n;
    if (n==1){
        sort_id(p);
    } else if (n==2){
        sort_date(p);
    }
}

void init(Restaurant *p) {
    p->orders[p->num].orderID = 3;
    p->orders[p->num].price = 10.5;
    p->orders[p->num].date.day = 15;
    p->orders[p->num].date.month = 1;
    p->orders[p->num].date.year = 1990;
    (p->num)++;

    p->orders[p->num].orderID = 2;
    p->orders[p->num].price = 20.55;
    p->orders[p->num].date.day = 15;
    p->orders[p->num].date.month = 2;
    p->orders[p->num].date.year = 2024;
    (p->num)++;

    p->orders[p->num].orderID = 4;
    p->orders[p->num].price = 10.5;
    p->orders[p->num].date.day = 20;
    p->orders[p->num].date.month = 2;
    p->orders[p->num].date.year = 2021;
    (p->num)++;

    p->orders[p->num].orderID = 1;
    p->orders[p->num].price = 30.1;
    p->orders[p->num].date.day = 20;
    p->orders[p->num].date.month = 2;
    p->orders[p->num].date.year = 2021;
    (p->num)++;
}


int main() {
    Restaurant res;
    res.num = 0;
    init(&res);
    int opt;
    opt=-1;
    while (opt!=0){
        cout<<"~~~~~~~~~Welcome!~~~~~~~~~~"<<endl;
        listOptions();
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cin>>opt;
        if(opt==1){
            add(&res);
        } else if(opt==2){
            show(&res);
        } else if(opt==3){
            del(&res);
        } else if(opt==4){
            sort(&res);
        } else if(opt==0){
            cout<<"Bye!";
        }
    }

    return 0;
}
