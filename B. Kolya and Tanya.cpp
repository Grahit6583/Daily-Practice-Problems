#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll MOD = 1e9 + 7;

ll expo(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1){
            res = (res * a) % MOD;
        }

        a = (a*a)%MOD;
        b >>= 1;
    }

    return res;
}

void solve(){
    ll n;
    cin>>n;

    ll allcases = expo(3,(3*n));
    ll badcases = expo(7,n);

    ll ans = (allcases % MOD - badcases % MOD + MOD) % MOD;
    cout<<ans<<"\n";

    return ;
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