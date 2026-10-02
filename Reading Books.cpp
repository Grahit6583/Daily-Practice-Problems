#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    ll sum = 0;
    ll maxi = LLONG_MIN;
    for(int i=0; i<n; i++){
        ll x;
        cin>>x;
        maxi = max(maxi,x);
        sum += x;
    }
    cout<<max(maxi*2,sum);
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