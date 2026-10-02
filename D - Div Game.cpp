#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool isPrime(ll n){
    if(n<=1){
        return false;
    }

    for(ll i=2; i*i<=n; i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;
}

ll power(ll a, ll b){
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

    if(isPrime(n)){
        cout<<1<<"\n";
        return;
    }
    ll ans = 0;
    for(ll i=2; i*i<=n; i++){
        if(n%i){
            continue;
        }
        ll cnt = 0;
        while(n%i==0){
            cnt++;
            n /= i;
        }
        
        ll need = 1;
        while(cnt >= need){
            cnt -= need;
            need++;
            ans++;
        }
    }
    if(n>1){
        ans++;
    }
    cout<<ans;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll t=1;

    while(t--){
        solve();
    }

    return 0;
}