#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    vector<ll> arr(n);
    vector<ll> freq(n+1,0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i] <= n){
            freq[arr[i]]++;
        }
    }

    ll ans = 0;
    vector<ll> cnt(n+1,0);
    for(int a = 1; a<=n; a++){ //for jumps
        if(freq[a] == 0){
            continue;
        }

        for(int x=a; x<=n; x+=a){// for coordinates
            cnt[x] += freq[a];
            ans = max(ans,cnt[x]);
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

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}