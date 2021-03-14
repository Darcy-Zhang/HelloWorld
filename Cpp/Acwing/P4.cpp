#include <cstdio>
#include <iostream>

static int volumn[1001], worth[1001], number[1001];
static int solu[1001][1001];
static int N, V;
int main()
{
    using namespace std;
    void sele(int m, int n);
    for (int m = 0; m < 1001; ++m)
        for (int n = 0; n < 1001; ++n)
            solu[m][n] = 0;
    cin >> N >> V;
    for (int i = 1; i <= N; ++i)
        scanf("%d%d%d", &volumn[i], &worth[i], &number[i]);
    for (int m = 1; m <= N; ++m)
        for (int n = 0; n <= V; ++n)
            sele(m, n);
    cout << solu[N][V] << endl;
    return 0;
}

void sele(int m, int n)
{
    int k = 0;
    int temp = 0;
    while (0 <= k * volumn[m] && k * volumn[m] <= n && k <= number[m])
    {
        temp = solu[m - 1][n - k * volumn[m]] + k * worth[m];
        if (temp > solu[m][n])
            solu[m][n] = temp;
        ++k;
    }
    return ;
}
