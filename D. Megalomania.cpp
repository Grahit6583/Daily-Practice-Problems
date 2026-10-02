#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    vector<pair<int,int>> job(n);

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;

        job[i] = {a,b};
    }

    sort(job.begin(),job.end(),[&](pair<int,int> &a, pair<int,int> &b){
        return a.second < b.second;
    });
    ll time = 0;

    for(int i=0; i<n; i++){
        time += job[i].first;
        if(time > job[i].second){
            cout<<"No\n";
            return;
        } 
    }

    cout<<"Yes\n";
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