#include <iostream>
#include <locale>
static unsigned long long Bx, By, Hx, Hy;

int main()
{
    bool check(unsigned long long a, unsigned long long b);
    using namespace std;
    cin >> Bx >> By >> Hx >> Hy;
    unsigned long long methods[25][25];
    for (unsigned long long i = 0; i < 25; ++i)
        for (unsigned long long j = 0; j < 25; ++j)
            methods[i][j] = 0;
    methods[0][0] = 1;
    for (unsigned long long i = 1; i <= Bx; ++i)
        if (check(i, 0) && check(i - 1, 0))
            methods[i][0] += methods[i - 1][0];
    for (unsigned long long j = 1; j <= By; ++j)
        if (check(0, j) && check(0, j - 1))
            methods[0][j] += methods[0][j - 1];
    for (unsigned long long i = 1; i <= Bx; ++i)
        for (unsigned long long j = 1; j <= By; ++j)
            if (check(i, j))
            {
                if (check(i - 1, j))
                    methods[i][j] += methods[i - 1][j];
                if (check(i, j - 1))
                    methods[i][j] += methods[i][j - 1];
            }
    cout << methods[Bx][By] << endl;
    return 0;
}

bool check(unsigned long long m, unsigned long long n)
{
    unsigned long long abs(unsigned long long a, unsigned long long b);
    if (abs(m, Hx) == 2 && abs(n, Hy) == 1)
        return 0;
    if (abs(m, Hx) == 1 && abs(n, Hy) == 2)
        return 0;
    if (m == Hx && n == Hy)
        return 0;
    return 1;
}

unsigned long long abs(unsigned long long a, unsigned long long b)
{
    if (a > b)
        return a - b;
    if (a < b)
        return b - a;
    return 0;
}
