#include <iostream>
using namespace std;

class Shape{
    public:
        void set(int w,int h){
            width=w;
            height=h;
        }
    protected:
        int width,height;
};

class Rectanguler: public Shape{
    public:
        void area(){
            cout<<"Area is: "<<width*height<<endl;
        }
        void perimeter(){
            cout<<"Perimeter is: "<<(width+height)*2<<endl;
        }
};
class PaintCost :public Rectanguler{
    public:
        void paintcost(){
            cout<<"Total paint cost is: "<<231*width*height<<endl;
        }
};

int main(){
    PaintCost p;
    int a,b;
    cout<<"Enter width:"<<endl;
    cin>>a;
    cout<<"Enter height:"<<endl;
    cin>>b;
    p.set(a,b);
    p.area();
    p.perimeter();
    p.paintcost();
    return 0;
}