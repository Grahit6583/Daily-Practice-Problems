#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    vector<int> freq(1e6+21);

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        freq[x]++;
    }
    int answer = 0;
    for(int i=0; i+1<1e6+21; i++){
        freq[i+1] += freq[i]/2;
        freq[i] &= 1;
        answer += freq[i];
    }

    cout<<answer<<"\n";
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