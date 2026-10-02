#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll MOD = 998244353;

vector<ll> fact(2e5+1);
ll modPow(ll a, ll b) {
    ll res = 1;

    while (b) {
        if (b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

ll modDivide(ll a, ll b) {
    // a / b mod MOD
    return (a * modPow(b, MOD - 2)) % MOD;
}


ll mod_mul(ll a, ll b){
    return (a%MOD * b%MOD)%MOD;
}

void factorial(){
    fact[0] = 1;
    for(int i=1; i<=2e5; i++){
        fact[i] = mod_mul(fact[i-1],i);
    }

    return;
}

void solve(){
    ll n;
    cin>>n;

    ll maxi = 0;
    map<ll,ll> mp;
    for(int i=0; i<n; i++){
        ll x;
        cin>>x;
        maxi = max(maxi,x);
        mp[x]++;
    }

    if(mp[maxi] > 1){
        cout<<fact[n]%MOD<<"\n";
        return;
    } else if(mp[maxi-1] == 0){
        cout<<0<<"\n";
        return;
    }
    ll total = fact[n];

    ll bad = modDivide(total, mp[maxi - 1] + 1);

    ll ans = (total - bad + MOD) % MOD;
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

    int t;
    cin >> t;
    factorial();
    while(t--){
        solve();
    }

    return 0;
}