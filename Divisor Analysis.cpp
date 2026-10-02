#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int MOD = 1e9 + 7;

ll expo(ll a, ll b){
    ll ans = 1;

    while(b){
        if(b & 1){
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

void solve(){
    int n;
    cin>>n;

    vector<ll> p(n),k(n);

    for(int i=0; i<n; i++){
        cin>>p[i]>>k[i];
    }

    ll div_cnt = 1, div_sum = 1, div_prod = 1, div_cnt1 = 1;

    for(int i=0; i<n; i++){
        div_cnt = div_cnt *(k[i] + 1) % MOD;
        div_sum = div_sum * (expo(p[i],k[i]+1)-1) % MOD * expo(p[i]-1,MOD-2) % MOD;
        div_prod = expo(div_prod,k[i]+1) * expo(expo(p[i],(k[i]*(k[i]+1))/2), div_cnt1) % MOD;
        div_cnt1 = div_cnt1 * (k[i] + 1) % (MOD-1);
    }

    cout<<div_cnt<<" "<<div_sum<<" "<<div_prod;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;

    while(t--){
        solve();
    }

    return 0;
}