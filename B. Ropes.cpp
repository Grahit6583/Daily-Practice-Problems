#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool possible(vector<int> &ropes, int n, ll k, double length){
    ll cnt = 0;
    for(int rope : ropes){
        cnt += rope/length;
        if(cnt >= k){
            return true;
        }
    }
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<int> ropes(n);

    for(int i=0; i<n; i++){
        cin>>ropes[i];
    }

    double l=0;
    double h=1e7;
    double error = 1e-7;
    double ans  = 0;
    while(h-l > error){
        double mid = (l+h)/2;
        if(possible(ropes,n,k,mid)){
            ans = mid;
            l = mid+error;
        }else{
            h = mid-error;
        }
    }

    cout<<setprecision(7)<<fixed<<ans<<"\n";
}