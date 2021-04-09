/*
 * @Author       : Darcy
 * @Date         : 2021-03-19 17:18:20
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-04-09 21:36:47
 * @FilePath     : \HelloWorld\Cpp\TXExersice\01\T1.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
#include <iostream>

using namespace std;
int main()
{
   void reverse(int *p);
   int N;
   cin >> N;
   int digits[100];
   int *p = digits;
   for (int i = 0; i < N; ++i)
   {
      for (int n = 0; n < 10; ++n)
         cin >> digits[n];
      reverse(p);
   }
   return 0;
}

void reverse(int *p)
{
   for (int i = 9; i >= 0; --i)
      cout << p[i] << ' ';
   cout << endl;
   return;
}
