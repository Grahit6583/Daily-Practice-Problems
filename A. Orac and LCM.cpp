#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 200000;

int spf[N + 1];

void sieve() {
    for (int i = 0; i <= N; i++) spf[i] = i;

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    sieve();

    int n;
    cin >> n;

    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (x > 1) {
            int p = spf[x];
            int cnt = 0;

            while (x % p == 0) {
                cnt++;
                x /= p;
            }

            mp[p].push_back(cnt);
        }
    }

    ll ans = 1;

    for (auto &[prime, vec] : mp) {

        sort(vec.begin(), vec.end());

        if(vec.size() == n){
            ans *= power(prime, vec[1]);
        }
        else if(vec.size() == n-1){
            ans *= power(prime, vec[0]);
        }
        // else: answer exponent is 0, do nothing
    }

    cout << ans << '\n';
}