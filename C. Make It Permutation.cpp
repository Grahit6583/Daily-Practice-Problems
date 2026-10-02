#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n,c,d;
    cin>>n>>c>>d;

    vector<ll> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    set<int> s;
    ll minCost = n*c+d;  //to remove all and add 1;
    ll duplicate = 0;
    for(int i=0; i<n; i++){
        if(s.find(arr[i]) == s.end()){
            s.insert(arr[i]);
        }else{
            duplicate++;
        }

        ll cost = 0;
        cost += (duplicate * c);

        if(((arr[i])-(i+1-duplicate)) > 0){
            cost += (((arr[i])-(i+1-duplicate)) * d);
        }
        cost += ((n-i-1)*c);
        minCost = min(minCost,cost);
    }

    cout<<minCost<<"\n";
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