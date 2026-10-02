#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll expo(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            res *= a;
        }
        a *= a;
        b >>= 1;
    }

    return res;
}

void solve(){
    ll n;
    cin>>n;

    ll a = expo(2,n);
    ll b = 0;

    for(int i = 1; i<(n/2); i++){
        a += expo(2,i);
    }

    for(int i=(n/2); i<n; i++){
        b += expo(2,i);
    }

    cout<<a-b<<"\n";
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