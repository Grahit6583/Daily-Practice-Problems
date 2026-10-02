#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;

    vector<ll> fruits(n);
    vector<ll> heights(n);
    
    for(int i=0; i<n; i++){
        cin>>fruits[i];
    }

    for(int i=0; i<n; i++){
        cin>>heights[i];
    }

    ll sum = 0;
    ll ans = 0;

    for(ll left=0, right=0; right<n; right++){
        if(right > 0 && heights[right-1] % heights[right] != 0){
            left = right;
            sum = 0;
        }
        sum += fruits[right];
        while(left<=right && sum > k){
            sum -= fruits[left];
            left++;
        }
        ans = max(ans,right-left+1);
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

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}