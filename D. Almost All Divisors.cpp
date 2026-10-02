#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    vector<ll> arr(n);
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    vector<ll> divisors;
    ll candidate = arr[0] * arr[n-1];

    for(ll i=2; i*i<=candidate; i++){
        if(candidate % i == 0){
            divisors.push_back(i);
            if(candidate/i != i){
                divisors.push_back(candidate/i); 
            }
        }
    }

    sort(divisors.begin(),divisors.end());

    if(divisors == arr){
        cout<<candidate<<"\n";
    }else{
        cout<<-1<<"\n";
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}