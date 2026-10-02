#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    string a,b;
    cin>>a>>b;

    int n = a.length();
    int m = b.length();

    vector<int> prefix(n,0);

    prefix[0] = (a[0]=='1');
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + (a[i]=='1');
    }

    int oneb = 0;
    for(int i=0; i<m; i++){
        if(b[i] == '1') oneb++;
    }

    int ans = 0;

    for(int i=0; i<=n-m; i++){
        int r = i+m-1;
        int onec = prefix[r]-(i==0 ? 0 : prefix[i-1]);
        if((onec % 2) == (oneb % 2)){
            ans++;
        }
    }

    cout<<ans;
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