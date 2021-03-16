#include <asm-generic/errno-base.h>
#include <iostream>

int main()
{
    using namespace std;
    int solu[100][100];
    for (int m = 0; m < 100; ++m)
        for (int n = 0; n < 100; ++n)
            solu[m][n] = 0;
    int N;
    cin >> N;
    int i = 1;
    int m = 1, n = 0;
    int check = N;
    while (check > 0)
    {
        for (int s = 0; s < check; ++s)
        {
            ++n;
            solu[m][n] = i;
            ++i;
        }
        --check;
        for (int s = 0; s < check; ++s)
        {
            ++m;
            --n;
            solu[m][n] = i;
            ++i;
        }
        --check;
        for (int s = 0; s < check; ++s)
        {
            --m;
            solu[m][n] = i;
            ++i;
        }
        --check;
    }
    int column = N;
    for (int x = 1; x <= N; ++x)
    {
        for (int y = 1; y <= column; ++y)
            cout << solu[x][y] << '\t';
        cout << endl;
        --column;
    }
    return 0;
}
