#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll powers(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1){
            res = res*a;
        }
        a = a*a;
        b>>=1;
    }
    return res;
}

void solve(){
    ll n;
    cin>>n;
    if(n%2){
        cout<<0;
        return;
    }
    int cnt = 1;
    ll divisor = 2*5;
    ll ans = 0;
    while(n/divisor > 0){
        ans += (n/divisor);
        cnt++;
        divisor = 2 * powers(5,cnt);
    }

    cout<<ans<<"\n";
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