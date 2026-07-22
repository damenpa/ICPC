#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vi v(n);

        for(auto &x : v){
            cin >> x;
        }

        DSU dsu = DSU(n);


        for(int i = 0; i < n; i++) {
            if(i + x < n) dsu.unite(i, i + x);
            if(i + y < n) dsu.unite(i, i + y);
        }

        int f = 0;

        for(int i = 0; i < n; i++) {
            if(dsu.find(i) != dsu.find(v[i] - 1)) {
                f = 1;
                break;
            }
        }

        if(!f)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    
}