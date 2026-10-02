#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int mod = 1e9+7;

ll mod_mul(ll a, ll b, ll mod){
    return ((a%mod)*(b%mod))%mod;
}

void solve(){
    int n,m;
    cin>>n>>m;

    char ch[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>ch[i][j];
        }
    }

    int diff_name = 1;

    for(int j=0; j<m; j++){
        set<char> st;
        for(int i=0; i<n; i++){
            st.insert(ch[i][j]);
        }

        ll uniqueCharInCol = st.size();
        diff_name = mod_mul(diff_name,uniqueCharInCol,mod);
    }

    cout<<diff_name<<"\n";
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