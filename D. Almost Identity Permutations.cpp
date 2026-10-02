#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n,k;
    cin>>n>>k;

    ll fact[5];

    fact[0] = 1;
    for(int i=1; i<=4; i++){
        fact[i] = fact[i-1] * i;
    }

    ll ans = 1;

    for(int i=2; i<=k; i++){
        ll res = fact[i];
        ll denominator = 1;
        int parity = -1;

        for(int j=1; j<=i; j++){
            denominator *= j;
            res += parity * (fact[i]/denominator);
            parity *= -1;
        }

        ll num = 1;

        for(int j=n; j>n-i; j--){
            num *= j;
        }

        ll ncr = num/fact[i];

        ans += res*ncr;
    }

    cout<<ans<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}