#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll MOD = 1e9+7;

ll mod_mul(ll a, ll b){
    return ((a%MOD) * (b%MOD))%MOD;
}

ll expo(ll a, ll b){
    ll res = 1; 
    while(b){
        if(b&1){
            res = (res * a) % MOD;
        }
        a = (a*a)%MOD;
        b>>=1;
    }

    return res;
}

void solve(){
    ll n,m;
    cin>>n>>m;

    ll fact[m+n+1];
    ll ifact[m+n+1];

    fact[0] = 1;
    for(ll i=1; i<=m+n; i++){
        fact[i] = mod_mul(fact[i-1],i);
    }

    ifact[m+n] = expo(fact[m+n],MOD-2);

    for(ll i=m+n-1; i>=0; i--){
        ifact[i] = mod_mul(ifact[i+1],i+1);
    }

    ll res = mod_mul(fact[m+n-1], ifact[n-1]);
    res = mod_mul(res, ifact[m]);

    cout<<res<<"\n";
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