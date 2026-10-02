#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    double a,b,c,d;
    cin>>a>>b>>c>>d;

    double p = a/b;
    double q = c/d;

    double ans = p/(p+q-(p*q));

    cout << fixed << setprecision(12) << ans << '\n';

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