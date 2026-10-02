#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;
    int ans = 0;
    for(int i=0; i<(k+1)/2; i++){
        vector<int> freq(26,0);

        for(int j=0; j<n; j+=k){
            freq[s[j+i]-'a']++;

            if(i != k-1-i){
                freq[s[j+k-1-i]-'a']++;
            }
        }
        int total = accumulate(freq.begin(), freq.end(), 0);
        int mx = *max_element(freq.begin(), freq.end());
        ans += (total-mx);
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