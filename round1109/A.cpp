#include <bits/stdc++.h>
using namespace std;

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
        string s;
        cin >> s;
        int largest = 0;
        int curr = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '#')
            {
                curr++;
            }
            else
            {
                largest = max(largest, curr);
                curr = 0;
            }
        }
        largest = max(largest, curr);

        cout << ceil((float)largest / 2) << endl;
    }
}