/*
 * @Author       : Darcy
 * @Date         : 2021-03-29 22:14:09
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-03-30 22:31:01
 * @FilePath     : \HelloWorld\Cpp\TXExersice\02\T2.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
#include <iostream>
#include <iomanip>
using namespace std;
class Date
{
public:
   /* 默认构造函数，以fullyear的形式给出年月日，默认值为1990年1月1日，同时设置
日期分隔符为“-” */
   Date(int year = 1990, int month = 1, int day = 1);
   /* get、set方法 */
   // 设置日期，如果有非法的月或日，将其置为1
   void setDate(int Year, int Month, int Day);
   void setYear(int Year);
   int getYear();
   void setMonth(int Month);
   int getMonth();
   void setDay(int Month);
   int getDay();
   void printFullYear();     // 以YYYY-MM-DD的形式打印，2011-01-08
   void printStandardYear(); // 以YY-MM-DD的形式打印，比如11-01-08
   /* 计算函数 */
   // 计算当前日期与参数日期之间相差几个整年，仅考虑参数日期比当前日期晚的情况
   int fullYearsTo(int year, int month, int day);
   /* 计算当前日期与参数日期之间相差多少天(考虑闰年)，如果参数日期在当前日期之前，返回负数。 */
   int daysTo(int year, int month, int day);

   int Year;
   int Month;
   int Day;
   char Separator; // 日期分隔符
};

int Date::daysTo(int year, int month, int day)
{
   int y2, m2, d2;
   int y1, m1, d1;

   m1 = (Month + 9) % 12;
   y1 = Year - m1 / 10;
   d1 = 365 * y1 + y1 / 4 - y1 / 100 + y1 / 400 + (m1 * 306 + 5) / 10 + (Day - 1);

   m2 = (month + 9) % 12;
   y2 = year - m2 / 10;
   d2 = 365 * y2 + y2 / 4 - y2 / 100 + y2 / 400 + (m2 * 306 + 5) / 10 + (day - 1);

   return (d2 - d1);
}
Date::Date(int year, int month, int day)
{
   Year = year;
   Month = month;
   Day = day;
}

void Date::printFullYear()
{
   printf("%4d-%02d-%02d\n", Year, Month, Day);
   return;
}
void Date::printStandardYear()
{
   printf("%02d-%02d-%02d\n", Year % 100, Month, Day);
}
int Date::fullYearsTo(int year, int month, int day)
{
   if (month < Month || (month == Month && day < Day))
      return year - Year - 1;
   return year - Year;
}
int main()
{
   Date birthDate(1969, 8, 11);
   birthDate.printFullYear();                          // 打印：1969-08-11
   birthDate.printStandardYear();                      // 打印：69-08-11
   cout << birthDate.fullYearsTo(2010, 4, 15) << endl; // 打印：40，满四十岁
   cout << birthDate.daysTo(2010, 4, 15) << endl;      // 打印14857，活了14857天了
   // 打印-7254，共和国比我早诞生了7254天
   cout << birthDate.daysTo(1949, 10, 1) << endl;
}
