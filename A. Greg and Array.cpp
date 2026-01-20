#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll> arr(n);
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<vector<ll>> opr(m,vector<ll>(3,0));

    for(ll i=0; i<m; i++){
        cin>>opr[i][0]>>opr[i][1]>>opr[i][2];
    }

    vector<vector<ll>> query(k,vector<ll>(2,0));

    for(ll i=0; i<k; i++){
        cin>>query[i][0]>>query[i][1];
    }

    vector<ll> pref_op(m,0);

    for(ll i=0; i<k; i++){
        ll l = query[i][0]-1;
        ll r = query[i][1]-1;

        pref_op[l]++;
        if(r != m-1){
            pref_op[r+1]--;
        }
    }

    for(ll i=1; i<m; i++){
        pref_op[i] += pref_op[i-1];
    }

    for(ll i=0; i<m; i++){
        opr[i][2] *= pref_op[i];
    }

    vector<ll> pref_arr(n,0);
    for(ll i=0; i<m; i++){
        ll l = opr[i][0]-1;
        ll r = opr[i][1]-1;
        ll d = opr[i][2];

        pref_arr[l] += d;
        if(r != n-1){
            pref_arr[r+1] -= d;
        }
    }

    for(ll i=1; i<n; i++){
        pref_arr[i] += pref_arr[i-1];
    }

    for(ll i=0; i<n; i++){
        arr[i] += pref_arr[i];
    }

    for(ll i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
