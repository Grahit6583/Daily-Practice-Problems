#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n,s;
    cin>>n>>s;

    vector<int> weight(n),cost(n);

    for(auto &i : weight){
        cin>>i;
    }

    for(auto &i : cost){
        cin>>i;
    }

    ll wt=0;
    ll c=0;
    ll ans = 0;

    for(int left=0, right=0; right<n; right++){
        wt += weight[right];
        c += cost[right];
        while(wt > s){
            wt -= weight[left];
            c -= cost[left];
            left++;
        }

        ans = max(ans,c);
    }

    cout<<ans;
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