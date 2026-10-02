#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll MOD = 1e9+7;

ll mod_mul(ll a, ll b, ll MOD){
    return (a % MOD) * (b % MOD) % MOD;
}

ll binary_expo(ll a, ll b){
    ll res = 1;

    while(b){
        if(b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    string s;
    cin>>s;

    int n = s.length();
    vector<ll> fact(n+1);
    vector<ll> ifact(n+1);

    fact[0] = 1;
    for(int i=1; i<=n; i++){
        fact[i] = mod_mul(fact[i-1],i,MOD);
    }

    ifact[n] = binary_expo(fact[n],MOD-2);

    for(int i=n-1; i>=0; i--){
        ifact[i] = mod_mul(ifact[i+1],i+1,MOD);
    }

    map<char,int> mp;
    for(char c : s){
        mp[c]++;
    }

    ll ans = fact[n];
    for(auto i : mp){
        ans *= ifact[i.second];
        ans %= MOD;
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