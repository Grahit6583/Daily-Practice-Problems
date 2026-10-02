#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll modPow(ll a, ll b) {
    ll res = 1;

    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    // factorials
    vector<ll> fact(k + 1), invFact(k + 1);

    fact[0] = 1;

    for (ll i = 1; i <= k; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invFact[k] = modPow(fact[k], MOD - 2);

    for (ll i = k; i >= 1; i--) {
        invFact[i - 1] = invFact[i] * i % MOD;
    }

    auto nCr = [&](ll a, ll b) -> ll {
        if (b < 0 || b > a)
            return 0;

        return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
    };

    ll firstPart = 0;

    // cycle length = c
    for (ll c = 1; c <= k; c++) {

        ll chooseCycle =
            nCr(k - 1, c - 1);

        ll arrangeCycle =
            fact[c - 1];

        ll attach;

        if (c == k) {
            // all nodes are already in the cycle
            attach = 1;
        } else {
            attach =
                c * modPow(k, k - c - 1) % MOD;
        }

        ll ways =
            chooseCycle *
            arrangeCycle % MOD *
            attach % MOD;

        firstPart =
            (firstPart + ways) % MOD;
    }

    // second part
    ll secondSize = n - k;

    ll secondPart =
        modPow(secondSize, secondSize);

    ll answer =
        firstPart * secondPart % MOD;

    cout << answer << '\n';

    return 0;
}