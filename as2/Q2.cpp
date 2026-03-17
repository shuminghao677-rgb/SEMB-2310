#include <iostream>
#include <algorithm>
using namespace std;

class Combination {
    private:
        int dNum;// number of dices
        int cNum;// number of different point sums
        long long int **pPtr; // pointing to a 2D array for each pair of occurrence and sum. Use long int to avoid overflow.
    public:
        Combination(int i = 1) {
            dNum=i;
            cNum=(6*i-1*i)+1;
            pPtr=new long long int*[cNum]; //给长度为cNum的一级整数数组指针的头元素分配二级指针是pPtr
            for(int k=0;k<cNum;k++){
                pPtr[k]=new long long int[2];//因为这里每个组合对象里有连个需要consider的属性一个是组合和一个是出现次数 所以一级指针申请的空间长度是2
                pPtr[k][0]=dNum+k;//相当于当前cNum中k的sum和是什么 i*i+k->6*i 初始化dNum+k
                pPtr[k][1]=0;//这个就是第二个属性 出现的个数 初始化是0
                }
                if(dNum==3){
                    findSum3();
                } else if(dNum==2){
                    findSum2();
                } else if(dNum==1){
                    findSum1();
                } else {
                    findSumRecursion(dNum,0);
                }
        }
        ~Combination() {
            for(int k=0;k<cNum;k++){
                delete[] pPtr[k];//先循环释放一级指针
            }
            delete[] pPtr; //再释放二级指针
            //因为是析构函数不需要对已释放内存的指针重新赋值空指针

        cout << "Memory is released" << endl;
        }
        void findSum1();
        void findSum2();
        void findSum3();
        void findSumRecursion(int left, int currentSum);
        void print();
        void sortBySum();
        void sortByOcc();
};

void Combination::findSum1() { //因为把成员函数写在class外面 所以需要Combination:: 作用域
    int dice1[6]={
        1,2,3,4,5,6
    };
    for(int i=0;i<6;i++){
        pPtr[dice1[i]-dNum][1]++;
    }
}
void Combination::findSum2() {
    int dice1[6]={
        1,2,3,4,5,6
    };
    int dice2[6]={
        1,2,3,4,5,6
    };
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            pPtr[dice1[i]+dice2[j]-dNum][1]++;
        }
    }
}
void Combination::findSum3() {
    int dice1[6]={
        1,2,3,4,5,6
    };
    int dice2[6]={
        1,2,3,4,5,6
    };
    int dice3[6]={
        1,2,3,4,5,6
    };
    for (int i=0;i<6;i++){
        for (int j=0;j<6;j++){
            for (int k=0;k<6;k++){
                pPtr[dice1[i]+dice2[j]+dice3[k]-dNum][1]++;
            }
        }
    }
}
void Combination::findSumRecursion(int left, int currentSum) {
    if (left == 0) {
        pPtr[currentSum - dNum][1]++;
        return;
    }
    for (int i = 1; i <= 6; i++) {
        findSumRecursion(left - 1, currentSum + i);
    }
}
void Combination::print(){
    for(int i=0;i<cNum;i++){
        cout<<pPtr[i][1]<<" occurrence(s) of sum "<<pPtr[i][0]<<endl;
    }
}
void Combination::sortBySum() {
    for(int i=0;i<cNum-1;i++){
        for(int j=cNum-1;j>i;j--){
            if(pPtr[j-1][0]<pPtr[j][0]){
                swap(pPtr[j-1],pPtr[j]);
            }
        }
    }
}
void Combination::sortByOcc() {
    for(int i=0;i<cNum-1;i++){
        for(int j=cNum-1;j>i;j--){
            if(pPtr[j-1][1]<pPtr[j][1]){
                swap(pPtr[j-1],pPtr[j]);
            }
        }
    }
}

void display(Combination &com) {
    int n;
    do {
        cout << "~~~~~~~~~~~~~~~~~" << endl;
        cout << "0 exit" << endl;
        cout << "1 sort by sum" << endl;
        cout << "2 sort by occurrence" << endl;
        cout << "~~~~~~~~~~~~~~~~~" << endl;
        cin >> n;
        switch(n) {
        case 0: cout << "Bye!" << endl; break;
        case 1: com.sortBySum(); com.print();break;
        case 2: com.sortByOcc(); com.print();break;
        }
        cout << endl;
    } while(n != 0);
}
int main() {
    int diceNum;
    cout << "Enter the number of dice:" << endl;
    cin >> diceNum;
    Combination com(diceNum);
    display(com);
    return 0;
}
        