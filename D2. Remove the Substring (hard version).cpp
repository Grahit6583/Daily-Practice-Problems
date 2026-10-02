#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<int> left(m), right(m);

    // Earliest positions
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[j]) {
            left[j] = i;
            j++;
            if (j == m) break;
        }
    }

    // Latest positions
    j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == t[j]) {
            right[j] = i;
            j--;
            if (j < 0) break;
        }
    }

    int ans = 0;

    // Remove prefix
    ans = max(ans, right[0]);

    // Remove suffix
    ans = max(ans, n - 1 - left[m - 1]);

    // Remove middle part
    for (int i = 0; i < m - 1; i++) {
        ans = max(ans, right[i + 1] - left[i] - 1);
    }

    cout << ans << '\n';
}

int main() {
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