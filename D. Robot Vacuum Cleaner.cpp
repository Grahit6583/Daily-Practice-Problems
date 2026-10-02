#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct info{
    ll s=0,h=0;
    string str;
};

void solve(){
    ll n;
    cin>>n;

    vector<info> v(n);

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        v[i].str = s;

        for(auto c : v[i].str){
            if(c == 's'){
                v[i].s++;
            }else{
                v[i].h++;
            }
        }
    }

    sort(v.begin(),v.end(),[&](const info &a, const info &b){
        return a.s * b.h > b.s * a.h;
    });

    ll ans = 0;
    ll sCnt = 0;
    for(auto &x : v){
        for(char ch : x.str){
            if(ch == 's'){
                sCnt++;
            }else{
                ans += sCnt;
            }
        }
    }

    cout<<ans<<"\n";

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