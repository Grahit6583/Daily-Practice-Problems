#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> a(n);
    vector<int> freq(m+1);
    vector<int> changesIndex;

    int changes = 0;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<n; i++){
        if(a[i] > m){
            changesIndex.push_back(i);
        }else{
            if(freq[a[i]] == n/m){
                changesIndex.push_back(i);
            }else{
                freq[a[i]]++;
            }
        }
    }

    for(int i=1; i<=m; i++){
        while(freq[i] < n/m){
            a[changesIndex.back()] = i;
            changesIndex.pop_back();
            changes++;
            freq[i]++;
        }
    }

    cout<<n/m<<" "<<changes<<"\n";
    for(auto i : a) cout<<i<<" ";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}