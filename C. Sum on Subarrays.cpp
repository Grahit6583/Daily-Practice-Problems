#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(int n, long long k) {
    if (n == 0) {
        return {};
    }

    if (k < n) {
        vector<long long> a(n, -1);
        if (k > 0) {
            a[k - 1] = 200;
        }
        a[k] = -400;
        return a;
    } else {
        vector<long long> a = solve(n - 1, k - n);
        a.push_back(1000);
        return a;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> b = solve(n, k);
        for (auto x : b) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
