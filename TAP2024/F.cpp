#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto &x : v)
    {
        cin >> x;
    }

    int score = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            score--;
        }

        if (v[i] == 1)
        {
            score++;
            if (i - 2 >= 0)
            {
                if (v[i - 1] == 1 && v[i - 2] == 1)
                {
                    score ++;
                }
            }
        }
    }

    cout << score << endl;
}