#include <iostream>
#include <map>
#include <iterator>
#include <iomanip>
int main() {
    int num1, num2; //两组多项式的项数;

    std::map<int, double> res;  //以指数为键存储

    std::cin >> num1;   //处理第一组
    for(int i = 0; i < num1; i++) {
        int exp;    //指数
        double coe; //幂

        std::cin >> exp >> coe;
        res.insert({exp, coe}); //直接插入
    }

    int size = 0;
    std::cin >> num2;   //第二组
    for(int i = 0; i < num2; i++) {
        int exp;
        double coe;

        std::cin >> exp >> coe;


        auto it = res.find(exp); //查找是否存在该指数
        if(it == res.end()) {
            res.insert({exp, coe}); //不存在直接插入
        } else {
            it->second += coe;  //存在则加上原来的
            if(it->second == 0)
                size--;     //识别0项
        }
    }

    std::cout << res.size() + size;

    for(auto it = res.rbegin(); it != res.rend(); it++) {
        if(it->second != 0) {
            std::cout << ' ' << it->first << ' '
                      << std::fixed << std::setprecision(1) << it->second;
            //注意控制位数
        }
    }

    return 0;
}
