#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Product{
    private:
        char name[11];
        int date;
        bool state;
    public:
        Product(){
            state=1;

        }
        Product(char *n, int d, bool s){
            strcpy(name,n);
            date=d;
            state=s;
        }
        char* getName(){
            return name;
        }
        int getDate(){
            return date;
        }
        bool getState(){
            return state;
        }
        void buy(){
            state=0;
        }
};
class Category{
    private:
        int count;
        Product list[100];
    public:
        Category(){ 
            count=0;
        }
        void add(char *n,int d,bool s){ 
            list[count]=Product(n,d,s);
            count++;
        }
        void sort(){
            for(int i=0;i<count-1;i++){
                for(int j=count-1;j>i;j--){
                    if(list[j-1].getDate()<list[j].getDate()){
                        swap(list[j-1],list[j]);
                    }
                }
            }
        }
        void show(){
            for(int i=0;i<count;i++){
                cout<<list[i].getName()<<" "<<list[i].getDate()<<" "<<list[i].getState()<<endl;
            }
        }
        bool purchase(char*t){
            for(int i=0;i<count;i++){
                if(strcmp(list[i].getName(),t)==0){
                    if(list[i].getState()==1){
                        list[i].buy();
                        return 1;
                    }
                }
            }
            return 0;
        }

};
class Store{
    private:
        Category Electronics;
        Category Clothing;
        Category Food;
    public:
        void add(){
            int n;
            cout<<"Input the number of products:"<<endl;
            cin>>n;
            char CategoryName[15];
            char tmpName[11];
            int tmpDate;
            bool tmpState;
            cout<<"Input the information of products (name, date, state, category):"<<endl;
            for(int i=0;i<n;i++){
                cin>>tmpName>>tmpDate>>tmpState>>CategoryName;
                if(strcmp(CategoryName,"Electronics")==0){
                    Electronics.add(tmpName,tmpDate,tmpState);
                }else if(strcmp(CategoryName,"Clothing")==0){
                    Clothing.add(tmpName,tmpDate,tmpState);
                }else{
                    Food.add(tmpName,tmpDate,tmpState);
                }
            }

        }
        void showALL(){
            cout<<"Products in the store:"<<endl;
            cout<<"Electronics:"<<endl;
            Electronics.sort();
            Electronics.show();
            cout<<"Clothing:"<<endl;
            Clothing.sort();
            Clothing.show();
            cout<<"Food:"<<endl;
            Food.sort();
            Food.show();
        }
        bool buyAny(char* n) {
            if (Electronics.purchase(n)) return true;
            if (Clothing.purchase(n)) return true;
            if (Food.purchase(n)) return true;
            return false;
        }
};

int main(){
    Store mystore;
    int choice=-1;
    char name[11];
    while(choice!=0){
        cout<<"~~~~~~~~~Welcome!~~~~~~~~~~"<<endl;
        cout<<"0: Exit"<<endl;
        cout<<"1: Add"<<endl;
        cout<<"2: Show"<<endl;
        cout<<"3: Purchase"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cin>>choice;
        if (choice==1){
            mystore.add();
        }else if(choice==2){
            mystore.showALL();
        }else if(choice==3){
                cout<<"Input the name of the product you want to purchase:"<<endl;
                while(true){
                    cin>>name;
                    if(mystore.buyAny(name)){
                        cout<<name<<endl;
                        cout<<"Succeed!"<< endl;
                        break;
                    }else{
                        cout << "Sorry, the product is not available. Try again:" << endl;
                    }
                }
        }else if(choice==0){
            cout<<"Bye!"<<endl;
        }else{
            cout<<"this number is invalid"<<endl;
        }
    }
    return 0;
}
