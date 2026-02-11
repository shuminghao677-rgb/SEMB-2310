//TODO 前面是name 后面是ID 分别打印

// * arr 用字符解决

#include <iostream>
#include <cstring> // 为了使用 strlen

using namespace std;

int main() {
    char arr[100]; // 声明固定大小的数组
    cout << "Enter student info (Name then ID):" << endl;
    
    // 1. 读取一整行（例如: "John Wick 007"）
    cin.getline(arr, 100);

    // 2. 找到字符串末尾
    int idx = strlen(arr) - 1;

    // 3. 从后往前走，直到遇到第一个空格
    // 这个空格就是“名字”和“ID”的分界线
    while (idx >= 0 && arr[idx] != ' ') {
        idx--;
    }

    // 4. 输出结果
    // 名字是从 0 到 idx 的部分
    cout << "Student name is: ";
    for (int i = 0; i < idx; i++) {
        cout << arr[i];
    }
    cout << endl;

    // ID 是从 idx + 1 到末尾的部分
    cout << "Student ID is: ";
    // 这里的条件 arr[i] != '\0' 就是你提到的结束判定
    for (int i = idx + 1; arr[i] != '\0'; i++) {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}


// * 用vector解决

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main(){
    vector<string> words;
    cout<<"Enter the student info:"<<endl;
    string tmp;
    while(cin>>tmp){
        words.push_back(tmp);
    }
    vector<string> ids;
    for (int i=(int)words.size()-1;i>=0;i--){ //!在这种列表遍历删减的时候就必须从后面遍历 不然会跳过
        if (isdigit(words[i][0])){
            ids.push_back(words[i]);
            words.erase(words.begin() + i);
        }
    }
    cout<<"Student name is: ";
    for (int i=0;i<(int)words.size();i++){
        cout<<words[i]<<" ";
    }
    cout<<endl;
    cout<<"Student ID is: ";
    for (int j=0;j<(int)ids.size();j++){
        cout<<ids[j]<<" ";
    }
    cout<<endl;
}