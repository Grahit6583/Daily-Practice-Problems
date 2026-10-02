#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;

    vector<pair<int,int>> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }

    sort(arr.begin(),arr.end(),[&](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    });

    multiset<ll> st;
    for(int i=0;i<k;i++) st.insert(LLONG_MIN);   // k empty seats, not pre-filled with real movies

    ll ans=0;
    for(int i=0;i<n;i++){
        auto it = st.upper_bound(arr[i].first); // largest free time <= start
        if(it == begin(st)){
            continue;
        }
        st.erase(--it);
        st.insert(arr[i].second);
        ans++;
    }
    cout<<ans;
    return ;
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