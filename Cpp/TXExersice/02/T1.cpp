/*
 * @Author       : Darcy
 * @Date         : 2021-03-28 23:25:25
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-03-28 23:37:16
 * @FilePath     : \HelloWorld\Cpp\TXExersice\02\T1.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
#include <iostream>

using namespace std;

class Box
{
public:
   double length;
   double width;
   double height;

   double surface(void);
   double volume(void);
};

double Box::surface(void)
{
   return 2 * (length * width + length * height + width * height);
}

double Box::volume(void)
{
   return length * width * height;
}

int main(void)
{
   Box Box1;
   cout << "长宽高分别为：";
   cin >> Box1.length >> Box1.width >> Box1.height;
   cout << "体积为：" << Box1.volume() << endl;
   cout << "表面积为：" << Box1.surface() << endl;

   return 0;
}