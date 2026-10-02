#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll rightMost(ll point,int m, vector<int> &b, vector<int> &runstart){
    int idx = lower_bound(b.begin(),b.end(),point)-b.begin();
    if(idx < m && b[idx] == point){
        return runstart[idx]-1;
    }
    return point;
}

bool solve(ll distance,int n, int k,  vector<int> &village, int m, vector<int> &b, vector<int> &runstart){
    ll used=0;
    int i=0;

    while(i<n){
        ll t = rightMost(village[i]+distance,m,b,runstart);
        if(t < village[i]-distance){
            return false;
        }
        used++;
        if(used > k){
            return false;
        }
        while (i < n && village[i] <= t + distance){
            i++;
        }
    }

    return true;
}

void solve(){
    int n,k,m;
    cin>>n>>k>>m;

    vector<int> village(n),b(m),runStart(m);

    for(int i=0; i<n; i++){
        cin>>village[i];
    }

    for(int i=0; i<m; i++){
        cin>>b[i];
    }

    for(int j=0; j<m; j++){
        runStart[j] = (j>0 && (b[j]==b[j-1]+1) ? runStart[j-1] : b[j]); 
    }

    ll low = 0;
    ll high = 1e9+1e5;

    while(low < high){
        ll mid = (low+high)/2;
        if(solve(mid,n,k,village, m, b,runStart)){
            high = mid;
        }else{
            low = mid+1;
        }
    }

    cout<<low;
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