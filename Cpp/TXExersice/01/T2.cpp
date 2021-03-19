#include <iostream>
#include <cstring>

using namespace std;

char temp;
int main()
{
    char * ins(char *p);
    char origin[1000];
    cin >> temp;
    while(cin >> origin);
    char * t = ins(origin);
    cout << t;
    return 0;
}

char * ins(char *p)
{
    size_t len = strlen(p);
    char *t = new char[len * 2];
    for (int x = 0; x < (int)len; ++x)
    {
        t[2 * x] = p[x];
        t[2 * x + 1] = temp;
    }
    return t;
}
