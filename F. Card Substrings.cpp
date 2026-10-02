#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n,m;
    cin>>n>>m;
    string s,t;

    cin>>s;
    cin>>t;
    vector<ll> freq(26);

    for(ll i=0; i<m; i++){
        freq[t[i]-'a']++;
    }

    ll left = 0;
    ll ans = 0;
    for(ll right=0; right<n; right++){
        freq[s[right]-'a']--;
        while(*min_element(freq.begin(),freq.end()) < 0){
            freq[s[left]-'a']++;
            left++;
        }
        ans += (right-left+1);
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

    ll t=1;

    while(t--){
        solve();
    }

    return 0;
}