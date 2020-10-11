#include <iostream>
#include <sstream>
#include <stack>
int main() {
    int num1, num2;
    std::cin >> num1 >> num2;
    std::ostringstream s;
    s << num1 + num2;   //转换格式
    std::string str(s.str());

    bool isNegative = 0;
    if(str.front() == '-') {    //判断正负
        isNegative = 1;
        str.erase(str.begin());
    }

    //std::cout << str; //测试输入

    int countDig = 0;   //位数计数器
    std::stack<char> res;
    for(std::string::reverse_iterator it = str.rbegin(); it != str.rend(); it++) {
        res.push(*it);
        ++countDig;
        if(!(countDig % 3) && it + 1 != str.rend()) {
            res.push(',');
        }
    }

    if(isNegative) {
        std::cout << '-';
    }

    while(!res.empty()) {
        std::cout << res.top();
        res.pop();
    }

    return 0;
}
