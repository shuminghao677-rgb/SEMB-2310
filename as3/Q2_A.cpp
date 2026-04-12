#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class MyArray{
    private:
        T* pAddress;
        int mSize;
        int mCapacity;
    public:
        MyArray(int mc){
            mCapacity=mc;
            pAddress=new T[mc];
            mSize=0;
        }
        ~MyArray(){
            delete[] pAddress;
            pAddress=nullptr;
        }
        MyArray(const MyArray&other){
            this->mSize=other.mSize;
            this->mCapacity=other.mCapacity;
            this->pAddress=new T[this->mCapacity];
            for(int i=0;i<other.mSize;i++){
                this->pAddress[i]=other.pAddress[i];
            }
        }
        MyArray& operator=(const MyArray& other){ 
            if(this==&other){
                return *this;
            }else{
                this->mSize=other.mSize;
                this->mCapacity=other.mCapacity;
                delete[] this->pAddress;
                pAddress=new T[this->mCapacity];
                for(int i=0;i<other.mSize;i++){
                this->pAddress[i]=other.pAddress[i];
                }
                return *this;
            }  
        }
        void pushBack(const T& val){
            if(mSize==mCapacity){
                cout<<"Inserting new value failed: the array is full."<<endl;
            }else{
                pAddress[mSize]=val;
                mSize+=1;
            }
        }
        T getMax(){
            T maxVal=pAddress[0];
            for(int i=0;i<mSize;i++){
                if(pAddress[i]>maxVal){
                    maxVal=pAddress[i];
                }
            }
            return maxVal;
        }
        T& operator[](int index){
            return pAddress[index];
        }
};
class MyClassInt{
    private:
        int val;
    public:
        MyClassInt(){
            val=0;
        }
        MyClassInt(int v){
            val=v;
        }
        MyClassInt& operator=(const MyClassInt& other){
            this->val=other.val;
            return *this;
        }
        bool operator>(const MyClassInt& other) const {
            return this->val>other.val;
        }
        friend ostream& operator<<(ostream& os,const MyClassInt& mc);

};
ostream& operator<<(ostream& os,const MyClassInt& mc){
    os<<mc.val;
    return os;
}
class MyClassArr{
    private:
        MyArray<int>* mArray;
        int len;
    public:
        MyClassArr(){
            mArray=nullptr;
            len=0;
        }
        MyClassArr(int arr[],int l){
            mArray=new MyArray<int>(l);
            len=l;
            for(int i=0;i<len;i++){
                mArray->pushBack(arr[i]);
            }
        }
        MyClassArr(const MyClassArr& other){
            this->len=other.len;
            this->mArray=new MyArray<int>(this->len);
            for(int i=0;i<len;i++){
                int val=other.mArray->operator[](i);
                this->mArray->pushBack(val);
            }
        }
        ~MyClassArr(){
            delete mArray;
            mArray=nullptr;
        }
        MyClassArr& operator=(const MyClassArr& other){
            if (this==&other){
                return *this;
            }else{
                delete this->mArray;
                this->mArray=nullptr;
                this->len=other.len;
                this->mArray=new MyArray<int>(this->len);
                for(int i=0;i<len;i++){
                    int val=other.mArray->operator[](i);
                    this->mArray->pushBack(val);
                }
                return *this;
            }
        }
        friend ostream& operator<<(ostream& os,const MyClassArr& other);
        bool operator>(const MyClassArr&other) const {
            for(int i=0;i<min(this->len,other.len);i++){
                if(this->mArray->operator[](i)>other.mArray->operator[](i)){
                    return true;
                }else if (this->mArray->operator[](i)<other.mArray->operator[](i)){
                    return false;
                }else{
                    continue;
                } 
            }
            if(this->len>other.len){
                    return true;
                } else if(this->len<other.len){
                    return false;
                } else{
                    return false;
                }
        }

};
ostream& operator<<(ostream& os,const MyClassArr& other){
    for(int i=0;i<other.len;i++){
        if (i==other.len-1){
            os<<other.mArray->operator[](i);
        }else{
            os<<other.mArray->operator[](i)<<" ";
        } 
    }
    return os;
}


void testPartA() {
    
	MyArray<int> arr1(5);
	int inputInt, inSize;
	cout << "Input the amount of variables to store in the int array: " << endl;
	cin >> inSize;
	cout << "Input the integers: " << endl;
	for (int i = 0; i < inSize; i++) {
		cin >> inputInt;
		arr1.pushBack(inputInt);
	}
	cout << "The max value of the array is: " << arr1.getMax() << endl;

	MyArray<char> arr2(5);
    char inputChar;
    int charSize;
    cout<<"Input the amount of variables to store in the char array: "<<endl;
    cin>>charSize;
    cout<<"Input the characters: "<<endl;
    for(int i=0;i<charSize;i++){
        cin>>inputChar;
        arr2.pushBack(inputChar);
    }
    cout << "The max value of the array is: " << arr2.getMax() << endl;
}

void testPartC(){
	MyArray<MyClassArr> arr(5);
    int inSize;
    cout<<"Input the amount of variables to store in the MyClassArr array: "<<endl;
    cin>>inSize;
    for(int i=0;i<inSize;i++){
        int size;
        cout<<"Input the size of MyArray "<<i+1<<": "<<endl;
        cin>>size;
        int* temPtr = new int[size];
        cout<<"Input array "<<i+1<<": "<<endl;
        for(int j=0;j<size;j++){
            cin>>temPtr[j];
        }
        MyClassArr object(temPtr,size);
        arr.pushBack(object);
        delete[]temPtr;
        temPtr=nullptr;
    }
    cout<<"The max value of the array is: "<<arr.getMax()<<endl;
}
int main() {
	testPartC();
	return 0;
}