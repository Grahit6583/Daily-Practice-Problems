#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    double m,n;

    cin>>m>>n;

    double ans = m;

    for(double i=m-1; i>=1; i--){
        double sub = pow(i/m,n);
        ans -= sub;
    }

    cout<<setprecision(16)<<ans<<"\n";
    return ;
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