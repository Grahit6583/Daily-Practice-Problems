#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    vector<int> a;
    int empty = 0;

    for(int i=0; i<n; i++){
        if(s[i] == '.'){
            empty++;
        }else{
            a.push_back(empty);
        }
    }

    int mid = (a.size() - 1)/2;
    ll ans = 0;
    for(auto x : a){
        ans += abs(x-a[mid]);
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

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}