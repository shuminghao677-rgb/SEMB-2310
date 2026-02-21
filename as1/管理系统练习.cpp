// ============================================================================
//                PROJECT: LIBRARY MANAGEMENT SYSTEM (Q4)
// ============================================================================
/**
 * @题目要求：
 * 1. 结构体嵌套 (Nested Structs):
 * - Author: name (string), gender (char 'M'/'F')
 * - Book: bookID (int), title (string), writer (Author), price (double)
 * - Library: storage (Book数组, N=10), count (int 计数器)
 * * 2. 核心功能 (Helper Functions):
 * - init(): 预设3-4本书籍数据。
 * - addBook(): 提示输入书名、作者名、作者性别、价格。注意 count 增加。
 * - showAll(): 打印所有书籍。要求 bookID 补零对齐(setw)，价格保留2位小数。
 * - searchByAuthor(): [重点] 输入作者名，循环匹配并打印该作者的所有书籍。
 * - sortBooks(): 提供菜单选择：
 * - 1: 按 bookID 升序 (从小到大)
 * - 2: 按 price 降序 (从高到低)
 * * 3. 技术要点:
 * - 所有 Helper 函数必须使用指针传参 (Library *p)。
 * - Main 函数使用 do-while 结构实现交互菜单。
 * - 字符串比较直接使用 ==。
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// ============================================================================
//                               Constants
// ============================================================================
const int MAX_BOOKS = 10;

// ============================================================================
//                               Data Structures
// ============================================================================

// Author: name (string), gender (char 'M'/'F')
struct Author{
    string name;
    char gender;
};
// Book: bookID (int), title (string), writer (Author), price (double)
struct Book{
    int bookID;
    string title;
    Author writer;
    double price;
};
// Library: storage (Book数组, N=10), count (int 计数器)
struct Library{
    Book storage[MAX_BOOKS];
    int count;
};


// ============================================================================
//                               Helper Functions
// ============================================================================
//  * - addBook(): 提示输入书名、作者名、作者性别、价格。注意 count 增加。
void addBook(Library *p){
    if(p->count>=MAX_BOOKS){
        cout<<"the library has already exceeded the upper limit";
    }
    else{cout<<"输入书名、作者名、作者性别、价格。"<<endl;
    cin>>p->storage[p->count].title>>p->storage[p->count].writer.name>>p->storage[p->count].writer.gender>>p->storage[p->count].price;
    p->count++;
    }
}

// ============================================================================
//                               Main Entry
// ============================================================================

// [在此处实现 main 函数，记得初始化 Library 并开启 do-while 循环]