/* 4
2
3
3
2
3

Enter New Sides for Triangle 1:
Enter New Sides for Triangle 2:
The Area 2.90474 of Triangle 1 is larger than area 2.82843 of Triangle 2.
4
2
3
3
4
5
Enter New Sides for Triangle 1:
Enter New Sides for Triangle 2:
The Area 6 of Triangle 2 is larger than area 2.90474 of Triangle 1.
4
2
3
4
2
3
Enter New Sides for Triangle 1:
Enter New Sides for Triangle 2:
The areas of the two triangles are identical. */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Triangle{
public:
    int A,B,C;
    double area=0;
    Triangle():A(0),B(0),C(0){}
    Triangle(int a,int b,int c):A(a),B(b),C(c){}
    bool isVal(){
        if (A+B>C && A+C>B && B+C>A){
            return true;
        } else{
            return false;
        }
    }
    double getArea(){
        if (isVal()){
            double s=(A+B+C)/2.0;
            area=sqrt(s*(s-A)*(s-B)*(s-C));
        }
        return area;
    }
};

int main(){
    cout<<"Enter New Sides for Triangle 1:"<<endl;
    Triangle triangle1;
    cin>>triangle1.A>>triangle1.B>>triangle1.C;
    cout<<"Enter New Sides for Triangle 2:"<<endl;
    Triangle triangle2;
    cin>>triangle2.A>>triangle2.B>>triangle2.C;
    double area1,area2;
    area1=triangle1.getArea();
    area2=triangle2.getArea();
    if (area1>area2){
        cout<<"The Area "<<area1<<" of Triangle 1 is larger than area "<<area2<<" of Triangle 2."<<endl;
    } else if (area1==area2){
        cout<<"The areas of the two triangles are identical."<<endl;
    } else{
        cout<<"The Area "<<area2<<" of Triangle 2 is larger than area "<<area1<<" of Triangle 1."<<endl;
    }
    return 0;
}
