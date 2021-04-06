/*
 * @Author       : Darcy
 * @Date         : 2021-04-05 15:15:08
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-04-05 16:26:28
 * @FilePath     : \HelloWorld\Cpp\TXExersice\03\T2.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
   int rank;
   int teamgrade;
   void setinfo(void);
   void printinfo(void);
   unsigned int getID(void);
   string getName(void);
   unsigned int getGrade(void);

private:
   unsigned int ID;
   string name;
   unsigned int grade;
};

void Student::setinfo()
{
   cin >> ID >> name >> grade;
   return;
}

void Student::printinfo()
{
   printf("%06d\t", ID);
   cout << name << '\t' << grade << endl;
   return;
}

unsigned int Student::getID()
{
   return ID;
}

string Student::getName()
{
   return name;
}

unsigned int Student::getGrade()
{
   return grade;
}

int main()
{
   bool comp(unsigned int a_grade, unsigned int b_grade, unsigned int a_id, unsigned int b_id);
   Student stu[4];
   for (int i = 0; i < 4; ++i)
   {
      stu[i].setinfo();
      stu[i].rank = i + 1;
   }
   bool t, u;
   for (int i = 0; i < 4; ++i)
      for (int n = 0; n < 3; ++n)
      {
         t = comp(stu[n].getGrade(), stu[n + 1].getGrade(), stu[n].getID(), stu[n + 1].getID());
         u = stu[n].rank > stu[n + 1].rank;
         if (t == u)
            swap(stu[n].rank, stu[n + 1].rank);
      }
   for (int i = 0; i < 4; ++i)
      for (int n = 0; n < 4; ++n)
         if (stu[n].rank == (i + 1))
            stu[n].printinfo();
   return 0;
}

bool comp(unsigned int a_grade, unsigned int b_grade, unsigned int a_id, unsigned int b_id)
{
   if (a_grade > b_grade)
      return true;
   else if (a_grade == b_grade)
      if (a_id > b_id)
         return true;
   return false;
}