#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n,k,m;
    cin>>n>>k>>m;

    if(k>m){
        cout<<"NO\n";
        return;
    }

    cout << "Yes\n";

    vector<int> prefix(n + 1);

    for (int i = 0; i <= n; i++)
        prefix[i] = i % k;

    for(int i=1;i<=n;i++){
        int x=(prefix[i]-prefix[i-1]+m)%m;
        if(x==0) x=m;
        cout<<x<<" ";
    }

    cout<<"\n";
    return;
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