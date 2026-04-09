#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T, class U>
class DayOfYear {
    public:
        DayOfYear (T m, U d): month(m), day(d)  {}
        void print();
    public:
        T month;
        U day;
};

template <class T, class U>
void DayOfYear<T, U>::print() {
    cout << month << " " << day << endl;
}