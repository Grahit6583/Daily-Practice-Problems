#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll MOD = 998244353;

ll power(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1)
            ans = ans * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

ll nCr(ll a, ll b) {
    if (b < 0 || b > a)
        return 0;

    vector<ll> fact(a + 1);

    fact[0] = 1;

    for (ll i = 1; i <= a; i++)
        fact[i] = fact[i - 1] * i % MOD;

    // nCr = a! / (b! * (a-b)!)
    // Modular inverse using Fermat:
    // x^(-1) = x^(n-2) mod n

    ll numerator = fact[a];
    ll denominator = fact[b] * fact[a - b] % MOD;

    ll inverse = power(denominator, MOD - 2);

    return numerator * inverse % MOD;
}

void solve(){
    ll n;
    cin>>n;

    vector<ll> arr(n);
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    ll ans = 1;
    for(ll i=0; i<n; i+=3){
        ll mx_weight = max({arr[i]+arr[i+1], arr[i+1]+arr[i+2], arr[i]+arr[i+2]});
        ll count = 0;
        if(arr[i] + arr[i+1] == mx_weight) count++;
        if(arr[i] + arr[i+2] == mx_weight) count++;
        if(arr[i+1] + arr[i+2] == mx_weight) count++;
        
        ans = (ans * count) % MOD;
    }
    
    cout<<(ans * nCr(n/3,n/6))%MOD<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    ll t=1;
    while(t--){
        solve();
    }

    return 0;
}