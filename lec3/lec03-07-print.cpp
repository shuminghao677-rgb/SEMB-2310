#include <iostream>
using namespace std;

int main() {
	int len;
	cin>>len;
	if (len<=0){
		cout<<"pleas enter a positive number! "<<endl;
	} else if (len%2==0){
        cout<<"pleas enter an odd number! "<<endl;
		} else{
			for (int i=0;i<len;i++){
				cout<<string(abs(((len-1)/2)-i),' ')<<string(len - 2 * abs(len / 2 - i),'*')<<endl;
			}
		}
		return 0;
	}
	
