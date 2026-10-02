#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

vector < ll > prime(10000001, 0);

void seive() {
    for (ll i = 1; i < 10000001; i++) {
        prime[i] = i;
    }
    for (ll i = 2; i < 10000001; i++) {
        if (prime[i] == i) {
            for (ll j = i * i; j < 10000001; j += i) {
                if (prime[j] == j) {
                    prime[j] = i;
                }
            }
        }
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    map < int, int > mp1, mp2, mp3;
    vector < int > a(n), b(m);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        while (x > 1) {
            int p = prime[x];
            int cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            mp1[p] += cnt;
        }
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b[i] = x;
        while (x > 1) {
            int p = prime[x];
            int cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            mp2[p] += cnt;
        }
    }

    for (auto it: mp1) {
        mp3[it.first] = min(mp1[it.first], mp2[it.first]);
    }

    mp1 = mp2 = mp3;

    for (int i = 0; i < n; i++) {
        int x = a[i];
        while (x > 1) {
            int p = prime[x];
            int cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            cnt = min(cnt, mp1[p]);
            mp1[p] -= cnt;
            while (cnt--) {
                a[i] /= p;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int x = b[i];
        while (x > 1) {
            int p = prime[x];
            int cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            cnt = min(cnt, mp2[p]);
            mp2[p] -= cnt;
            while (cnt--) {
                b[i] /= p;
            }
        }
    }

    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++) {
        cout << b[i] << " ";
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    seive();
    while (t--) {
        solve();
    }

    return 0;
}