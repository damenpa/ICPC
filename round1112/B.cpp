#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t --) {
        int n; 
        int k;
        cin >> n >> k;

        if(k > n - 2) {
            cout << - 1 << endl;
            continue;
        }

        vector<int> res;

        int one = ceil((float)k / 2);
        one ++;
        int zero = floor((float)k / 2);
        zero ++;

        for(int i = 0; i < one; i++) {
            res.push_back(1);
        }
        for(int i = 0; i < zero; i++) {
            res.push_back(0);
        }

        int missing = n - (one + zero);

        if(n % 2 == 0 && (missing & 1)) {
            missing --;
            cout << 0;
        } 


        for(int i = 0; i < missing; i++) {
            if(i % 2 == 0) {
                res.push_back(1);
            } else {
                res.push_back(0);
            }
        }
        
        for(auto x : res) {
            cout << x;
        }
        cout << endl;
    }
}