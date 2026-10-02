#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    vector<ll> arr;
    for(int i=0; i<n; i++){
        int x; 
        cin>>x;

        auto it = upper_bound(arr.begin(),arr.end(),x);
        if(it == arr.end()){
            arr.push_back(x);
        }else{
            arr[it-arr.begin()] = x;
        }
    }

    cout<<(int)arr.size()<<"\n";
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