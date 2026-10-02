#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;

    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<ll> peaks(n,0);
    for(int i=1; i<n-1; i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            peaks[i] = 1;
        }
    }

    ll ans = 0;
    ll cnt = 0;
    ll mini = -1;
    int i=1, j=1;

    while(j<n-1){
        cnt += peaks[j];

        if(j-i+1 > k-2){
            cnt -= peaks[i];
            i++;
        }
        if(ans < cnt){
            ans = cnt;
            mini = i;
        }

        j++;
    }
    if(mini == -1){
        cout<<1<<" "<<1<<"\n";
        return;
    }

    cout<<ans+1<<" "<<mini<<"\n";
    return;
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