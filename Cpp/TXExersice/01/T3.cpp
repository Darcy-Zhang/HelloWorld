/*
 * @Author       : Darcy
 * @Date         : 2021-03-19 17:18:20
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-03-19 18:00:33
 * @FilePath     : \HelloWorld\Cpp\TXExersice\01\T3.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
#include <cstdint>
#include <iostream>

using namespace std;
int origin[7][7];
int main()
{
    for (int m = 0; m < 7; ++m)
        for (int n = 0; n < 7; ++n)
            cin >> origin[m][n];
    bool t = 1;
    for (int m = 0; m < 7; ++m)
    {
        int maxn = -1;
        int maxx = -0x7fffffff;
        for (int n = 0; n < 7; ++n)
            if (origin[m][n] > maxx)
            {
                maxn = n;
                maxx = origin[m][n];
            }
        for (int x = 0; x < 7; ++x)
            if (origin[x][maxn] < maxx)
                continue;
        cout << maxx << endl;
        t = 0;
        break;
    }
    if (t)
        cout << "no" << endl;
    return 0;
}