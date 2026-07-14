#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    
    vector<ll> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    ll a = v[n-1];
    ll b = a;

    ll c = v[0];

    ll costo = a*b + b*c + c*a;
    ll ganancia = a*a + b*b + c*c;

    cout << ganancia - costo << endl;
}