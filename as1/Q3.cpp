/******************************************************************************
 * @File        : Q3.cpp
 * @Version     : 1.0.0
 * @Author      : Teresa
 * @Date        : 2026-02-17
 * @Description : 一个餐厅的自动点单系统包含结构体和helper函数的知识点
 * @Note        : 学习一些项目流程注释
 ******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string> //因为用了string字符串 所以引用liberary
#include <vector> //用了能装字符串的列表 所以有vector
using namespace std;
// ============================================================================
//                               constants
// ============================================================================

const int N = 10; //一开始定下来 订单的容量N是10 用const 就是把这个变量写死

// ============================================================================
//                               data structures
// ============================================================================

/**
 * @brief 关于日期的结构体
 * @struct Date
 */

struct Date {
    int day; //三个attribute 分别是 day month 和 year变量类型都是int
    int month;
    int year;
};
/**
 * @brief 嵌套的一个结构体 订单的结构体里面包含着Date日期
 * @struct Order
 */

struct Order {
    int orderID;
    double price;
    Date date;// 一个结构体来作为 attribute 变量名就是 date
};

/**
 * @brief 餐厅的结构体 此时包含十个订单的订单组 
 * @struct 以及已有的订单计数 num
 */

struct Restaurant {
    Order orders[N];
    int num;
};
// ============================================================================
//                               helper functions
// ============================================================================

/**
 * @brief  展示订单系统菜单
 * 
 * @param  没有参数
 * @return void 返回菜单 各种数字对应的功能
 */

void listOptions() {
    cout<<"0: Exit"<<endl;
    cout<<"1: Add"<<endl;
    cout<<"2: Show"<<endl;
    cout<<"3: Delete"<<endl;
    cout<<"4: Sort"<<endl;
    
}
/**
 * @brief  增加订单函数
 * 
 * @param  p    Restaurant餐厅结构体指针
 * @return void 表示订单已满 或者增加输入的订单到订单组 更新num
 */


void add(Restaurant *p) { //这里要考虑我们处理的是什么来选择什么结构体的指针 因为处理的是订单组 所以是餐厅结构体
    cout<<"Input OrderID:"<<endl;
    cout<<"Input Price:"<<endl;
    cout<<"Input Order Date (dd mm yyyy):"<<endl;
    cout<<endl;
    if (p->num>=N){
        cout<<"Order list is full."<<endl;//这里只要是计数大于等于餐厅的计数上限就不再增加订单
    } else{
        cin>>p->orders[p->num].orderID;//形参是指针 所以访问所有attribute 都需要p->orders p->num 
        cin>>p->orders[p->num].price;//对于num 是因为此时有num个订单所以 对num索引正好就是最新空的那个
        cin>>p->orders[p->num].date.day>>p->orders[p->num].date.month>>p->orders[p->num].date.year;
        p->num++;//并且所以赋值结束之后要更新num 此时订单数量增加了
    }
}

/**
 * @brief  关于展示此时已有订单 基本是对已有结构体里的赋值进行重新排版展示
 * 
 * @param  p    Restaurant 餐厅结构体
 * @return void 循环内输出每一个订单重新排版的订单号 价格 和日期
 */

void show(Restaurant *p) {
    cout<<setprecision(2);
    cout<<fixed; //* setprecision(2) 和 fixed 对结果只保留两位小数 
    if(p->num==0){//如果没有订单就说 no orders 所以需要num的数据 结构体指针选择餐厅
        cout<<"no orders"<<endl;
    } else{
        for (int i=0;i<p->num;i++){ //对订单号 进行排序 
            string s=to_string(p->orders[i].orderID);// *先把整数转化成字符串 to_string 函数
            if ((int)s.length()==1){
                s="00"+s; //如果订单是一位数 就补00
            } else if((int)s.length()==2){
                s="0"+s; //如果订单是两位数 就补0
            }else{
                s=s;//剩下的如果是三位数 就他本身
            }
            cout<<s<<"     "<<p->orders[i].price<<"   "<<p->orders[i].date.day<<'-'<<p->orders[i].date.month<<'-'<<p->orders[i].date.year<<endl;
            //这个地方就是对所有订单 还有结果 还有日期的重新输出排版
        }
        }
    cout<<endl;
    }
/**
 * @brief  删除已有订单组里的订单 更新计数
 * @new variable id 要删订单 index 订单在订单组里的索引
 * @param  p    Restaurant结构体指针
 * @return void 如果有输入的订单号就删除 没有就提示字符串没有该订单
 * @new tech 删除数组的其中一个元素用 循环内a[i]=a[i+1] 循环开始i=idx 结束是i小于len-1
 */

void del(Restaurant *p) {
    int id;//定义一个选择的订单号
    cout<<"Enter the orderID to be deleted"<<endl;
    cin>>id;
    int index=-1;
    for(int i=0;i<p->num;i++){
        if(p->orders[i].orderID==id){
            index=i;//通过循环在订单组里面要找要删的订单号 
            break;//找到索引就结束循环 用 break
        } else{
            index=index; //找不到index就保持原来的 说明找不到想要删的订单
        }
    }
    //接下来就是来判断如果 如果找到索引 怎么删除 或者没找到索引就提示
    if (index==-1){
        cout<<"The orderID cannot be found"<<endl;
    } else{
        //在数组里面删除一个元素就是从这个index索引开始 a[idx]=a[idx=1] 此时循环开始是idx 结束是len-1
        for(int j=index;j<p->num-1;j++){
            p->orders[j]= p->orders[j+1];
        }
        p->num--;//并在循环结束后对num数量进行更新
    }
    cout<<endl;
}
/**
 * @brief  按照订单号从小到大的大小bubble sort排序
 * 
 * @param  p    Restaurant 餐厅结构体
 * @return void 就是对orders 订单组重新排序 没有返回和输出
 */

void sort_id(Restaurant *p) {//标准的一个bubble sort 按照订单号的大小排序 别忘了p->orders[j].orderID 来比较订单号的大小
    for (int i=0;i<p->num-1;i++){
        for (int j=p->num-1;j>i;j--){
            if (p->orders[j].orderID<p->orders[j-1].orderID){
                Order tmp;//在swap的时候交换的是订单 也就是orders[j-1]和[j]
                tmp=p->orders[j];
                p->orders[j]=p->orders[j-1];
                p->orders[j-1]=tmp;
            }
        }
    }
}
/**
 * @brief  根据日期和价格 来重新排序订单组 就是日期越来越大 然后 相同日期的时候订单价格越来越大
 * @new variable 两个date就是排序的两个date 和一个判断有没有swap的整数【这里其实最好定义 Order1 Order2】
 * @param  p    指向结构体的指针
 * @return void 描述返回值
 * @new tech 冒泡排序加上 ifelse 先比较年份再比较月份 再比较日期 如果日期一样再按照价格高低排序
 */

void sort_date(Restaurant *p) {
    for (int i=0;i<p->num-1;i++){
        for (int j=p->num-1;j>i;j--){
            Date date1=p->orders[j-1].date;
            Date date2=p->orders[j].date; //冒泡搭建好一个正循环 一个逆循环之后
            int swap=0;
            //这里是根据 date1.year 还有当年分相同的时候月份 当月份相同时候的日期 还有当日期相同时候的订单号
            //来决定要不要交换 
            if (date1.year>date2.year){
                swap=1;//前面订单的年份比后面啊 要交换
            } else if(date1.year==date2.year){
                if (date1.month>date2.month){
                    swap=1; //年份相同的时候 月份大所以要交换
                } else if(date1.month==date2.month){
                    if (date1.day>date2.day){
                        swap=1;//月份大的时候 日期大要交换
                    } else if (date1.day==date2.day){
                        if (p->orders[j-1].price<p->orders[j].price){
                            swap=1;//日期相同的时候价格高要交换 这里其实可以一开始定义变量 Order1 和 Order2 然后Order1.date.year 这样子
                            //因为这里还需要 price价格属于 order的attribute
                        } else{
                            swap=0;//如果都不满足就swap=0 ⑨不需要交换
                        }
                        }
                }
            }
            if (swap==1){ //同时在bubble sort里层循环里 如果是swap==1 需要虚幻
                Order tmp;//建立中间变量
                tmp=p->orders[j]; //对两个订单交换 如果本来定义的是 Order1 Order2 就不需要再p->orders[j],p->orders[j-1]
                p->orders[j]=p->orders[j-1];
                p->orders[j-1]=tmp;
            }
        }
    }
    
}
/**
 * @brief  选择排序方式
 * 
 * @param  p    还是餐厅指针 因为这个函数里面需要 调用别的函数 进行一个指针转发
 * @return void 根据输入的数字 决定是对订单组进行哪种排序
 */

void sort(Restaurant *p) {//! 这里的参数是必须的 因为有调用 sort_id 和 sort_date都需要餐厅指针
    cout<<"1: Sort by orderID"<<endl;
    cout<<"2: Sort by date"<<endl;
    cout<<endl;
    int n;//选择哪种排序
    cin>>n;
    if (n==1){
        sort_id(p);//这里是不是就是 指针传参 如果是变量值就是&struct 这里直接指针p就好了
    } else if (n==2){
        sort_date(p);
    }
}
/**
 * @brief  初始化原来的订单组 通过一直更新num++ 赋值订单组里的不同订单
 * 
 * @param  p    餐厅结构体指针
 * @return void 只进行初始化 赋值填充给orders num是4个
 */

void init(Restaurant *p) {
    p->orders[p->num].orderID = 3;
    p->orders[p->num].price = 10.5;
    p->orders[p->num].date.day = 15;
    p->orders[p->num].date.month = 1;
    p->orders[p->num].date.year = 1990;
    (p->num)++; //这里是订单组的第一个订单 然后马上num更新 就赋值到第二个订单了

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
    (p->num)++;// 一共初始化 四个订单 这里更新的原因是 一开始是0 都赋值完是索引3 和个数之间还需要+1
}
// ============================================================================
//                               main entry
// ============================================================================
/**
 * @brief  程序主入口 (Main Control Loop)
 * @details 初始化餐厅和此时的订单个数 已经根据输入调度不通过能
 * @new variable opt 就是用户选择的输入解锁不同功能
 * @return int 程序退出状态码 (0: 正常退出)
 */


int main() {
    Restaurant res; //*初始化餐厅
    res.num = 0;//*初始化 订单个数一开始是0
    init(&res); //* 这里是初始化数据 调用helper函数 原来void里写的是 Restaurant指针
    //* 但是调用这里就要写 &加上原变量 但在helper调用其他helper函数的时候就是直接 p 形参一样写p->Restaurant 指针转发

    int opt; //定义opt 这个变量

    do{ //用do while 函数 只要点进去这个函数就要进行这个输入选择
        cout<<"~~~~~~~~~Welcome!~~~~~~~~~~"<<endl;
        listOptions();//调用展示功能菜单
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cin>>opt; //输入的值 是opt
        if(opt==1){
            add(&res);//不同的值 调用不同的功能 调用指针传参就是 &加变量
        } else if(opt==2){
            show(&res);
        } else if(opt==3){
            del(&res);
        } else if(opt==4){
            sort(&res);
        } else if(opt==0){
            cout<<"Bye!";
        }
    } while (opt!=0);//do while语法 就是只有在不等于0的时候才再次继续 等于0 直接结束

    return 0;
}
