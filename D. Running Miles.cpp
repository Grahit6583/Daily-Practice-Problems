#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    vector<ll> b(n+1);
    for(int i=1;i<=n;i++) cin >> b[i];

    vector<ll> A(n+1), C(n+1);
    for(int i=1;i<=n;i++){
        A[i] = b[i] + i;
        C[i] = b[i] - i;
    }

    vector<ll> prefA(n+2, LLONG_MIN);
    vector<ll> sufC(n+2, LLONG_MIN);

    for(int i=1;i<=n;i++)
        prefA[i] = max(prefA[i-1], A[i]);

    for(int i=n;i>=1;i--)
        sufC[i] = max(sufC[i+1], C[i]);

    ll ans = LLONG_MIN;
    for(int j=2;j<=n-1;j++){
        ll leftBest = prefA[j-1];   // max A_i, i<j
        ll rightBest = sufC[j+1];   // max C_k, k>j
        ans = max(ans, leftBest + b[j] + rightBest);
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}