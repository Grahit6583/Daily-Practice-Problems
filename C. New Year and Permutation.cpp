#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mod_mul(ll a, ll b, ll mod){
    return (a%mod * b%mod)%mod;
}

void solve(){
    ll n,m;
    cin>>n>>m;

    ll ans  = 0;
    vector<ll> fact(n+1);
    fact[0]=1;
    for(int i=1; i<=n; i++){
        fact[i] = mod_mul(fact[i-1],i,m);
    }
    for(int i=1; i<=n; i++){
        ll ways = mod_mul(n-i+1, n-i+1, m);
        ways = mod_mul(ways, fact[i], m);
        ways = mod_mul(ways, fact[n-i], m);

        ans = (ans + ways) % m;
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