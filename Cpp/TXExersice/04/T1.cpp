/*
 * @Author       : Darcy
 * @Date         : 2021-04-09 16:35:38
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-04-11 16:15:10
 * @FilePath     : \HelloWorld\Cpp\TXExersice\04\T1.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
#include <iostream>
using namespace std;

class ARR {
  public:
    ARR(int x[], int size);
    void change(void);
    void show(void);

  private:
    int n;
    int a[100];
};

ARR::ARR(int x[], int size) {
    n = size;
    memcpy(a, x, n * sizeof(int));
}

void ARR::change() {
    int *p = a;
    int *q = p + n - 1;
    while (p != q) {
        while (*q >= 0 && p < q)
            q--;
        while (*p <= 0 && p < q)
            p++;
        if (p < q)
            swap(*p, *q);
    }
}

void ARR::show() {
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << endl;
}

int main() {
    int b[10] = {1, -3, -1, 3, 2, 4, -4, 5, -5, -2};
    ARR test(b, 10);
    test.show();
    test.change();
    test.show();
    return 0;
}
