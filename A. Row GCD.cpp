#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<ll> a(n),b(m);

    for(ll i=0; i<n; i++){
        cin>>a[i];
    }

    for(ll i=0; i<m; i++){
        cin>>b[i];
    }

    ll g=0;
    for(ll i=1; i<n; i++){
        g = gcd(abs(a[i]-a[0]),g);
    }

    for(ll i=0; i<m; i++){
        ll ans = gcd(abs(a[0]+b[i]),g);
        cout<<ans<<" ";
    }
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll t=1;

    while(t--){
        solve();
    }

    return 0;
}