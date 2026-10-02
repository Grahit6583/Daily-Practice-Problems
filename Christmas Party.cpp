#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const ll MOD = 1e9 + 7;

// modular multiplication
ll mod_mul(ll a, ll b, ll m) {
    return (a % m) * (b % m) % m;
}

// modular exponentiation: a^b mod m
ll mod_pow(ll a, ll b, ll m) {
    ll result = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) result = mod_mul(result, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return result;
}

// modular inverse using Fermat's little theorem (m must be prime)
ll mminvprime(ll a, ll m) {
    return mod_pow(a, m - 2, m);
}

ll derangement(ll n, vector<ll>& fact, vector<ll>& ifact) {
    ll result = 0;
    for (ll k = 0; k <= n; k++) {
        ll term = mod_mul(fact[n], ifact[k], MOD);   // n! / k!
        if (k % 2 == 0)
            result = (result + term) % MOD;
        else
            result = (result - term + MOD) % MOD;    // subtract, handle negative mod
    }
    return result;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> fact(n + 1);
    vector<ll> ifact(n + 1);

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mod_mul(fact[i - 1], i, MOD);
    }

    ifact[n] = mminvprime(fact[n], MOD);
    for (int i = n - 1; i >= 0; i--) {
        ifact[i] = mod_mul(ifact[i + 1], i + 1, MOD);
    }

    cout << derangement(n, fact, ifact) << endl;
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