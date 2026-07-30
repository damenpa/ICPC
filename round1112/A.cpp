#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t --) {
        int n; 
        cin >> n;
        
        vi v(n);
        for(auto &x : v) {
            cin >> x;
        }

        if(n & 1) {
            cout << "NO" << endl;
            continue;
        }

        vi odd;
        vi even;

        for(int i = 0; i < n; i ++) {
            if ((i + 1) % 2 == 1) odd.push_back(v[i]);
            else even.push_back(v[i]);
        }

        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());

        if(odd.front() > even.back() + 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}