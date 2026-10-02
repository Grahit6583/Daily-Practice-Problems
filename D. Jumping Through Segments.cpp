#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<ll,ll> intersection(pair<ll,ll> &a, pair<ll,ll> &b){
    return {max(a.first,b.first),min(a.second,b.second)};
}

bool possible(vector<pair<ll,ll>> &ranges, ll mid, int n){
    pair<ll,ll> currRange = {0,0};

    for(int i=0; i<n; i++){
        currRange = {currRange.first - mid, currRange.second + mid};
        pair<ll,ll> des = ranges[i];
        pair<ll,ll> final = intersection(currRange,des);

        if(final.first <= final.second){
            currRange = final;
        }else{
            return false;
        }
    }

    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n; 
        cin>>n;

        vector<pair<ll,ll>> ranges(n);

        for(int i=0; i<n; i++){
            cin>>ranges[i].first>>ranges[i].second;
        }

        ll l = 0;
        ll h = 1e9;
        ll ans  = 0;
        while(l<=h){
            ll mid = (l+h)/2;

            if(possible(ranges,mid,n)){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }

        cout<<ans<<"\n";
    }

}