/*
 * @Author: larry combofish@163.com
 * @Date: 2024-02-25 16:50:07
 * @LastEditors: larry combofish@163.com
 * @LastEditTime: 2024-02-29 10:14:24
 * @FilePath: /code-write/src/02-25/test_01.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cctype>
#include <icecream.hpp>

using namespace std;
int main(int argc, char const *argv[])
{

    char a = '1', b = 'A', c = ',', d = ' ';
    IC(a, b, c, d);

    // IC(std::islower(b), std::isupper(b),
    //    std::tolower(b), std::toupper(b),
    //    std::isdigit(a));

    IC(std::isalnum(a)); // 检查字符是否为英文或者数字
    IC(std::ispunct(c));
    IC(std::ispunct(a)); // 检查参数c是否为标点符号或特殊符号

    // std::isapace(d);

    return 0;
}
