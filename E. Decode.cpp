#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    // Prefix sums range from -n to +n
    int offset = n;

    vector<ll> sum(2 * n + 1, 0);

    int pref = 0;

    // pref[0] = 0
    // For a = 0, store (a + 1) = 1
    sum[offset] = 1;

    ll ans = 0;

    for (int b = 1; b <= n; b++) {

        if (s[b - 1] == '1')
            pref++;
        else
            pref--;

        int id = pref + offset;

        // All previous a with pref[a] == pref[b]
        ans = (ans + sum[id] * (n - b + 1)) % MOD;

        // Current prefix index can act as 'a' later
        sum[id] = (sum[id] + (b + 1)) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}