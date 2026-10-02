#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;

    const int MAX = 1000000;
    vector<int> freq(MAX + 1);

    int mx = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
        mx = max(mx, x);
    }

    for (int d = mx; d >= 1; d--) {
        int cnt = 0;

        for (int multiple = d; multiple <= mx; multiple += d) {
            cnt += freq[multiple];
            if (cnt >= 2) {
                cout << d;
                return ;
            }
        }
    }

    return;
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