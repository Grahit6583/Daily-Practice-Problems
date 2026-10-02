#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

const int N = 10000001;
vector < bool > primes(N, true);
vector < bool > conjecture(N, false);
vector < int > prefix(N, 0);

void sieve() {
    primes[0] = primes[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (primes[i]) {
            for (int j = i * i; j < N; j += i) {
                primes[j] = false;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << prefix[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    sieve();

    for (int x = 1; x <= 3162; x++) {
        for (int y = 1; y <= 56; y++) {
            int sum = x * x + y * y * y * y;
            if (sum <= N && primes[sum]) {
                conjecture[sum] = true;
            }
        }
    }

    prefix[0] = conjecture[0];
    for (int i = 1; i < N; i++) {
        prefix[i] = prefix[i - 1] + conjecture[i];
    }

    while (t--) {
        solve();
    }

    return 0;
}