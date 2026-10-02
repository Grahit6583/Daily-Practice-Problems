#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int MOD = 998244353;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    map<int,int> mp;

    for(int i=0; i<n; i++){
        mp[a[i]] = i;
    }

    int ans=1;
    int idx=0;
    for(int i=0; i<n-1; i++){
        idx = max(idx,mp[a[i]]);
        if(i == idx){
            ans = (ans*2)%MOD;
        }
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