#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    vector<pair<long long, string>> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i].second>>a[i].first;
    }

    sort(a.begin(),a.end());

    long long answer = 0;

    for(int i=1; i<=n; i++){
        answer += (abs(i-a[i-1].first));
    }

    cout<<answer<<"\n";
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