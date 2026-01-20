#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll solve(){
    ll b,c,d;
    cin>>b>>c>>d;
    ll ans = 0;
    for(int i=0; i<=61; i++){
        ll b_ = (b >> i) & 1LL;
        ll c_ = (c >> i) & 1LL;
        ll d_ = (d >> i) & 1LL;
        
        if((b_ == 0 && c_ == 1 && d_ == 1) || (b_ == 1 && c_ == 0 && d_ == 0)){
            return -1;
        }

        if((b_ == 0 && c_ == 0 && d_ == 1) || (b_ == 1 && c_ == 1 && d_ == 0)){
            ans = ans | (1LL<<i);
        }
    }

    return ans;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        cout<<solve()<<"\n";
    }

    return 0;
}
