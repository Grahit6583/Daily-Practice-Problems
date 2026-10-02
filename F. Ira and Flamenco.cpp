#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll MOD = 1e9+7;

int mul(int x, int y){
    return (x*1LL*y)%MOD;
}

int power(int x, int y){
    int ans = 1;
    while(y>0){
        if(y&1) ans=mul(ans,x);
        x = mul(x,x);
        y = y>>1;
    }

    return ans;
}

int divide(int x, int y){
    return mul(x,power(y,(MOD-2)));
}

void solve(){
    ll n,m;
    cin>>n>>m;

    set<int> st;
    map<int,int> mp;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        st.insert(x);
        mp[x]++;
    }

    vector<int> distinct(st.begin(),st.end());

    ll i=0;
    ll prod=1;
    ll ans=0;

    for(ll j=0; j<(int)distinct.size(); j++){
        while(i < (int)distinct.size() && distinct[i]-distinct[j]<m){
            prod = (prod * 1LL * mp[distinct[i]])%MOD;
            i++;
        }

        if(i-j == m){
            ans = (ans + prod) % MOD;
        }
        prod = divide(prod,mp[distinct[j]]);
    }

    cout<<ans<<"\n";
    return ;
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