#include "lib.h"
#include <string>
#include <iostream>

using namespace std;

int findMax(int n1,int n2){
    return (n1>n2) ? n1:n2;
}

void greet(string name){
    cout<<"Hello  "<<name<<endl;
}