#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll> segments(n);
    for(int i=0; i<n; i++){
        cin>>segments[i];
    }

    ll min_len_of_tape = n;
    vector<ll> gaps;

    for(int i=1; i<n; i++){
        gaps.push_back(segments[i]-segments[i-1]-1);
    }

    sort(gaps.begin(),gaps.end());

    for(int i=0; i<n-k; i++){
        min_len_of_tape += gaps[i];
    }

    cout<<min_len_of_tape<<endl;

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