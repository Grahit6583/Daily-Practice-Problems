#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    cout<<(1LL<<(n+1))-2<<"\n";

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