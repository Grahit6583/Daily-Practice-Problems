#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n,k1,k2;
    cin>>n>>k1>>k2;

    vector<int> a(n),b(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<n; i++){
        cin>>b[i];
    }

    priority_queue<ll> diff;
    for(int i=0; i<n; i++){
        diff.push(abs(a[i]-b[i]));
    }

    ll k = k1+k2;

    while(k--){
        ll temp = diff.top();
        diff.pop();
        diff.push(abs(temp-1));
    }

    ll ans = 0;

    while(!diff.empty()){
        ll temp = diff.top();
        diff.pop();
        ans += temp * temp;
    }

    cout<<ans<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}