#include <iostream>

static int solu[1001];
static int cost[1001];
static int worth[1001];
static int N, V;
int main()
{
    using namespace std;
    int max(int a, int b);
    for (int i = 0; i < 1001; ++i)
        solu[i] = 0;
    cin >> N >> V;
    for (int i = 1; i <= N; ++i)
        cin >> cost[i] >> worth[i];
    int sum = 0;
    for (int i = 1; i <= N; ++i)
        sum += cost[i];
    for (int i = 1; i <= N; ++i)
    {
        for (int v = V; v >= max(cost[i], V - sum); --v)
            solu[v] = max(solu[v], solu[v - cost[i]] + worth[i]);
        sum -= cost[i];
    }
    cout << solu[V] << endl;
    return 0;
}

int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}
// #include <cstdio>
// #include <iostream>
// 
// int main()
// {
//     using namespace std;
//     int solu[1001][1001];
//     for (int m = 0; m < 1001; ++m)
//         for (int n = 0; n < 1001; ++n)
//             solu[m][n] = 0;
//     int N, V;
//     cin >> N >> V;
//     int volumn[1001], worth[1001];
//     for (int i = 1; i <= N; ++i)
//         scanf("%d%d", &volumn[i], &worth[i]);
//     for (int n = 0; n <= V; ++n)
//         solu[0][n] = 0;
//     for (int m = 1; m <= N; ++m)
//         for (int n = 0; n <= V; ++n)
//             if (n < volumn[m] || solu[m - 1][n] > (solu[m - 1][n - volumn[m]] + worth[m]))
//                 solu[m][n] = solu[m - 1][n];
//             else
//                 solu[m][n] = solu[m - 1][n - volumn[m]] + worth[m];
//     cout << solu[N][V] << endl;
//     return 0;
// }
