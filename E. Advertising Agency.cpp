#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1000;
const ll MOD = 1e9 + 7;

template <class T>
class Math {
public:

    vector<T> fact, infact;

    Math(ll n) {

        fact.resize(n);
        infact.resize(n);

        fact[0] = 1;

        // factorial
        for(ll i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        // inverse factorial of (n-1)
        infact[n - 1] = modinv(fact[n - 1]);

        // remaining inverse factorials
        for(ll i = n - 1; i >= 1; i--) {
            infact[i - 1] = infact[i] * i % MOD;
        }
    }

    T modinv(T x, T m = MOD) {
        return expo(x, m - 2, m);
    }

    T expo(T base, T exp, T m = MOD) {

        T res = 1;

        while(exp) {

            if(exp & 1) {
                res = res * base % m;
            }

            base = base * base % m;
            exp >>= 1;
        }

        return res;
    }

    T choose(T n, T k) {

        if(k < 0 || k > n)
            return 0;

        return fact[n] * infact[k] % MOD * infact[n - k] % MOD;
    }
};


void solve(Math<ll>& m) {

    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);

    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());

    // k-th largest element
    ll x = arr[k - 1];

    ll greater = 0;
    ll total = 0;

    for(ll i = 0; i < n; i++) {

        if(arr[i] > x) {
            greater++;
        }

        if(arr[i] == x) {
            total++;
        }
    }

    // Number of x's that we need to choose
    ll need = k - greater;

    ll ans = m.choose(total, need);

    cout << ans << '\n';
}


int main() {

//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    ll t;
    cin >> t;

    // Precompute ONCE
    Math<ll> m(N + 1);

    while(t--) {
        solve(m);
    }

    return 0;
}