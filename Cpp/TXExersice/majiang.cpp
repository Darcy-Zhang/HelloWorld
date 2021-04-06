/*
 * @Author       : Darcy
 * @Date         : 2021-04-06 11:31:40
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-04-06 11:50:49
 * @FilePath     : \HelloWorld\Cpp\TXExersice\majiang.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
#include <iostream>

using namespace std;

class Dice
{
public:
   void throwdice(int times = 1);
   void display(void);

private:
   int diceCount = 0;
};

void Dice::display()
{
   cout << "目前点数为：" << diceCount << endl;
   return;
}

void Dice::throwdice(int times)
{
   for (int i = 0; i < times; ++i)
   {
      diceCount = rand() % 6 + 1;
      Dice::display();
   }
   return;
}

int main()
{
   Dice A;
   int b;
   cin >> b;
   A.throwdice(b);
   return 0;
}