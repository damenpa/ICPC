#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t --) {
        int n; cin >> n;
        vi v(n);

        for(auto &x : v) {
            cin >> x;
        }

        if(n & 1) {
            cout << "NO" << endl;
            continue;
        }

        

        vi prefix(n);
        prefix[0] = v[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + v[i];

            if(prefix[i] == 4) {
                if(prefix[i-2] == 2) {
                    prefix[i] = 0;
                }
            }
            if(prefix[i] == -4) {
                if(prefix[i-2] == -2) {
                    prefix[i] = 0;
                }
            }
        }
        cout << (prefix[n-1] == 0 ? "YES" : "NO") << endl;
    }
}