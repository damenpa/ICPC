#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (ll &x : v)
        {
            cin >> x;
        }

        int f = 0;

        for (int i = 0; i < n - 1; i++)
        {
            v[i + 1] += v[i] - 1 - i;
            v[i] -= v[i] - 1 - i;

            if (v[i] >= v[i + 1])
            {
                f = 1;
                break;
            }
        }

        if (f)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}