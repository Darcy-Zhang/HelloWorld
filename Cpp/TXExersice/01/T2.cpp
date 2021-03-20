/*
 * @Author       : Darcy
 * @Date         : 2021-03-19 17:18:20
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-03-19 17:28:57
 * @FilePath     : \HelloWorld\Cpp\TXExersice\01\T2.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
#include <iostream>
#include <cstring>

using namespace std;

static char temp;
static char origin[1000];
static char newarray[1000];
int main()
{
    void convert(void);
    cin >> temp;
    cout << "输入字符串并以<C-z>结尾" << endl;
    cin >> origin;
    convert();
    return 0;
}

void convert(void)
{
    size_t len = strlen(origin);
    for (int x = 0; x < (int)len; ++x)
    {
        newarray[2 * x] = origin[x];
        newarray[2 * x + 1] = temp;
    }
    cout << newarray;
}
