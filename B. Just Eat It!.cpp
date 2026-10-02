#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    vector<ll> arr(n);
    ll total = 0;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        total += arr[i];
    }

    ll sum1 = arr[0];
    ll currSum1 = arr[0];
    for(int i=1; i<n-1; i++){
        currSum1 = max(arr[i],arr[i]+currSum1);
        sum1 = max(sum1,currSum1);
    }

    ll sum2 = arr[1];
    ll currSum2 = arr[1];
    for(int i=2; i<n; i++){
        currSum2 = max(arr[i],arr[i]+currSum2);
        sum2 = max(sum2,currSum2);
    }
    
    ll sum = max(sum1,sum2);
    if(total > sum){
        cout<<"YES\n";
        return;
    }

    cout<<"NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}