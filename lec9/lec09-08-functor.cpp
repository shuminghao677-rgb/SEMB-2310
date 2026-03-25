#include <iostream>
using namespace std;

class Course {
    public:
        Course (int i, int s): id(i), score(s) {}
		
        int id;
        double score;
};


int main() {

    Course c1(1111, 90), c2(2222, 95);

    
    return 0;
}
