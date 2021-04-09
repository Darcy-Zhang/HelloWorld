/*
 * @Author       : Darcy
 * @Date         : 2021-04-06 11:13:47
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-04-09 21:37:12
 * @FilePath     : \HelloWorld\Cpp\TXExersice\tollgate.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
#include <iostream>

using namespace std;

class Tollgate
{
 public:
   void input(void);
   void display(void);
   void charge(void);

 private:
   const int bigcar = 10;
   const int smallcar = 5;
   int cash = 0;
};

void Tollgate::display()
{
   cout << "目前收取的总费用为" << cash << "元" << endl;
   return;
}

void Tollgate::charge()
{
   int b, s;
   cout << "大车数量：";
   cin >> b;
   cout << "小车数量：";
   cin >> s;
   cash += b * bigcar;
   cash += s * smallcar;
   return;
}
void Tollgate::input(void)
{
   char temp = '\0';
   cout << "hit d for display, c for charge and e for exit(d/c/e)";
   while ((temp = getchar()) != 'e')
   {
      if (temp == 'd')
         Tollgate::display();
      else if (temp == 'c')
         Tollgate::charge();
      else
         cout << "hit d for display, c for charge and e for exit(d/c/e)";
   }
   return;
}

int main()
{
   Tollgate T;
   T.input();
   return 0;
}
