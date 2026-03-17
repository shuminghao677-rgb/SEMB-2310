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
            pPtr=new long long int*[cNum]; 
            for(int k=0;k<cNum;k++){
                pPtr[k]=new long long int[2];
                pPtr[k][0]=dNum+k;
                pPtr[k][1]=0;
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
                delete[] pPtr[k];
            }
            delete[] pPtr;
            

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

void Combination::findSum1() { 
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
        
