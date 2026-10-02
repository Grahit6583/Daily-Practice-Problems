#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll a,b;
    cin>>a>>b;

    ll ans = 1;

    while(a != b){
        if(a>b){
            ans += a/b;
            a %= b;
            if(a==0){
                ans--;
                break;
            }
        }else{
            ans += b/a;
            b %= a;
            if(b==0){
                ans--;
                break;
            }
        }
    }

    cout<<ans<<"\n";
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