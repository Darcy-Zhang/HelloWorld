#include <cstdint>
#include <iostream>

using namespace std;
int origin[100][100];
int M, N;
int main()
{
    int maximum(int *p);
    int check(int **p);
    for (int m = 0; m < 100; ++m)
        for (int n = 0; n < 100; ++n)
            origin[m][n] = 0;
    M = 7;
    N = 7;
    int **q;
    for (int i = 0; i < 7; ++i)
    {
        q = &origin;
        int a = maximum(p);
    }

}

int maximum(int *p)
{
    int maxn = -1;
    int m;
    for (m = 0; m < M; ++m)
        if (p[m] > maxn)
            maxn = m;
    return maxn;
}

int check(int **q, int num)
{
    int i;
    int min = 0x7fffffff;
    for (i = 0; i < 7; ++i)
        if (q[i][num] < min)
            min = i;
    return i;
}


