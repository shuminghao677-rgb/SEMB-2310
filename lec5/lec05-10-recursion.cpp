#include <iostream>
using namespace std;
//递归写法
//if n is 0; return 1
//else return n *f(n-1)
int factorial1 (int n){
    if (n==0){
        return 1;
    } else {
        return n *factorial1(n-1);
    }
}

//迭代器写法
int factorial2(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact = fact*i;
    }
    return fact;
}


int main() {
	int n;
    cout << "Enter n: ";
    cin >> n;

//	int ans1 = factorial1(n);
//	cout << "factorial1 is " << ans1 << endl;
    int ans1=factorial2(n);
    cout<< "factorial1 is " << ans1 << endl;

//	int ans2 = factorial2(n);
//	cout << "factorial2 is " << ans2 << endl;
	

	return 0;
}
