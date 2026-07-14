#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;

    if(n & 1 || n == 2) {
        cout << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    vector<int> div;
    for(int i = 2; i <= n/2; i++) {
        if(n % i == 0) {
            div.push_back(i);
        }
    }

    cout << div.size() << endl;
    for(auto x : div) {
        cout << 1 << " " << x << endl;
    }

}