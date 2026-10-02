#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

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
        ll n,a,b;
        cin>>n>>a>>b;

        vector<ll> arr(n);

        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        ll g = __gcd(a,b);

        for(int i=0;i<n;i++){
            arr[i] %= g;
        }

        sort(arr.begin(),arr.end());

        ll ans = arr[n-1] - arr[0];

        for(int i=0;i<n-1;i++){
            ans = min(ans, arr[i] + g - arr[i+1]);
        }

        cout<<ans<<"\n";
    }
}