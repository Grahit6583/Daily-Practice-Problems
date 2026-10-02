#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    vector<int> types(n+1);

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        types[x]++;
    }

    sort(types.begin(),types.end(),greater());

    int sum = 0;
    for(int i=0; i<n; i++){
        if(i) types[i] = max(0,min(types[i],types[i-1]-1));
        sum += types[i];
    }   

    cout<<sum<<"\n";
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