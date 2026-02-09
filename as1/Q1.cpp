/*
  题目：输入整数 -> 各位求和 (Sum) -> 取 Sum 末位 (N) -> 画 N 个空心三角形。
 核心逻辑：
 1. 字符转数字：s[i] - '0'
 2. N 个三角形：第 i 个三角形有 i+1 行 (i从0起)
 3. 打印重复字符：string(数量, '字符')  <-- 注意单引号
 4. 底边宽度：2*i + 3
 5. 对齐：以 N 为中心偏移量，最底行左侧不留空格。
 */
	
// 23434124
// Please enter an integer number:
// Sum of 23434124 is: 23
// The last digit of the sum is: 3
//    *
//   ***
//    *
//   * *
//  *****
//    *
//   * *
//  *   *
// *******
//    *
//    *
//    *

#include <iostream>
#include <string> // TODO 必须包含 string 类才能使用构造函数
using namespace std;

int main(){
    int num;
    cin >> num;

    string s = to_string(num); 
    int sum = 0;
    for (int i = 0; i < (int)s.length(); i++){ 
        sum += (s[i] - '0'); // ! 重点：char 减 '0' 得到真正的数字
    }

    int last_digit = sum % 10; //TODO 取最后一位digit直接除以10取余数

    for (int i = 0; i < last_digit; i++){
        cout << string(last_digit, ' ') << '*' << endl;
        for (int j = 0; j < i; j++){
            cout << string(last_digit - (j + 1), ' ') << '*' << string(2 * j + 1, ' ') << "*" << endl;
        }
        // ! 3. 打印底边 (注意：C++ 必须用 string(n, 'char')，不能用乘号)
        cout << string(last_digit - (i + 1), ' ') << string(2 * i + 3, '*') << endl;
    }
    for (int i = 0; i < last_digit; i++){
        cout << string(last_digit, ' ') << '*' << endl;
    }
    return 0;
}
