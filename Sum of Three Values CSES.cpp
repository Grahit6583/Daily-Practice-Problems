#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int searching(vector<pair<ll,ll>> &bs, ll remain, int ind, ll n){
    int l = ind+1;
    int r = n-1;

    while(l<=r){
        int mid = (l+r)/2;

        ll ele = bs[mid].first;

        if(ele == remain){
            return mid;
        }
        if(ele < remain){
            l = mid+1;
        }else{
            r=mid-1;
        }
    }

    return -1;
}

vector<ll> solve(){
    ll n,x;
    cin>>n>>x;

    vector<ll> arr(n);
    vector<pair<ll,ll>> bs(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
        bs[i] = {arr[i],i};
    }

    sort(bs.begin(),bs.end());

    for(int i=0; i<n-2; i++){ // a
        for(int j=i+1; j<n-1; j++){
            ll sum = bs[i].first + bs[j].first;
            ll remain = x-sum;
            int ind = searching(bs,remain,j,n);
            if(ind != -1){
                return {bs[i].second,bs[j].second,bs[ind].second};
            }
        }
    }
    return {};
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
        vector<ll> ans = solve();
        if((int)ans.size() == 0){
            cout<<"IMPOSSIBLE";
        }else{
            sort(ans.begin(),ans.end());
            cout<<ans[0]+1<<" "<<ans[1]+1<<" "<<ans[2]+1;
        }
    }

    return 0;
}