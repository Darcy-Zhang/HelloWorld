/*
 * @Author       : Darcy
 * @Date         : 2021-04-09 17:06:54
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-04-09 22:48:59
 * @FilePath     : \HelloWorld\Cpp\TXExersice\04\T2.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
#include <iostream>
using namespace std;

class RECT {
  public:
    RECT(double x1, double y1);
    virtual double area();
    double peri();
    virtual int isSquare();

  protected:
    double x, y;
};

class CUB : public RECT {
  public:
    CUB(double x1, double y1, double z1);
    double volume();
    double area();
    int isSquare();

  private:
    double height;
};

RECT::RECT(double x1, double y1) {
    x = x1;
    y = y1;
}

CUB::CUB(double x1, double y1, double z1) : RECT(x1, y1) { height = z1; }

double RECT::area() { return x * y; }

double RECT::peri() { return 2 * x + 2 * y; }

int RECT::isSquare() { return (x == y) ? 1 : 0; }

double CUB::volumn() { return area() * height; }

double CUB::area() {}

int main() {
    CUB cu;
    RECT *re = cu;
    cu.volume();
    re->area();
    re->isSquare();
    return 0;
}
