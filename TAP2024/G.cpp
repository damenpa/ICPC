#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int t = 0;
    int p = 0;
    int a = 0;
    int u = 0;

    for (auto c : s)
    {
        if (c == 'T')
        {
            t++;
        }
        if (c == 'P')
        {
            p++;
        }
        if (c == 'A')
        {
            a++;
        }
        if (c == 'U')
        {
            u++;
        }
    }

    int count = 0;

    while (t && a && p)
    {
        t--;
        a--;
        p--;
        count++;
    }

    while (t && u && p)
    {
        t--;
        u--;
        p--;
        count++;
    }

    cout << count << endl;

    return 0;
}