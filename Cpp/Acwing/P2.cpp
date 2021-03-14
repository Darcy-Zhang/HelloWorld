#include <cstdio>
#include <iostream>

int main()
{
    using namespace std;
    int solu[1001][1001];
    for (int m = 0; m < 1001; ++m)
        for (int n = 0; n < 1001; ++n)
            solu[m][n] = 0;
    int N, V;
    cin >> N >> V;
    int volumn[1001], worth[1001];
    for (int i = 0; i < N; ++i)
        scanf("%d%d", &volumn[i], &worth[i]);
    for (int n = 0; n <= V; ++n)
        solu[0][n] = 0;
    for (int m = 1; m <= N; ++m)
        for (int n = 0; n <= V; ++n)
            if (n < volumn[m] || solu[m - 1][n] > (solu[m - 1][n - volumn[m]] + worth[m]))
                solu[m][n] = solu[m - 1][n];
            else
                solu[m][n] = solu[m - 1][n - volumn[m]] + worth[m];
    cout << solu[N][V] << endl;
    return 0;
}

