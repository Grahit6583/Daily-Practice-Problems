#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    long long n, k;
    cin >> n >> k;

    if (k >= 43) {
        cout << "No";
        return;
    }

    for (long long i = 1; i <= k; i++) {
        if ((n + 1) % i != 0) {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
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