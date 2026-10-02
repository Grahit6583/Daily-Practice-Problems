#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<int> find_string(string &s, string &t){
    vector<int> ans;

    for(int i = 0; i + (int)t.size() <= (int)s.size(); i++){
        bool ok = true;
        for(int j = 0; j < (int)t.size(); j++){
            if(s[i+j] != t[j]){
                ok = false;
                break;
            }
        }
        if(ok) ans.push_back(i);
    }

    return ans;
}

void solve(){
    string s;
    cin>>s;

    int n;
    cin>>n;

    vector<string> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    map<string,vector<int>> mp;

    for(int i=0; i<n; i++){
        vector<int> temp = find_string(s,arr[i]);
        if(temp.size()){
            for(int j=0; j<(int)temp.size(); j++){
                mp[arr[i]].push_back(temp[j]);
            }
        }
    }
    int l = s.length();
    vector<int> ind(l,l+1);
    for(auto it : mp){
        int t = it.second.size();
        for(int i=0; i<t; i++){
            int start = it.second[i];
            int end = start + it.first.size() - 1;
            ind[start] = min(ind[start], end);
        }
    }

    vector<int> dp(l+1);
    dp[l] = l-1;
    for(int i=l-1; i>=0; i--){
        dp[i] = dp[i+1];

        if(ind[i] <= dp[i]){
            dp[i]  = ind[i]-1;
        }
    }

    int ans = 0;
    int index = 0;

    for(int i=0; i<l; i++){
        if(ans < dp[i]-i+1){
            ans = dp[i]-i+1;
            index = i;
        }
    }

    cout<<ans<<" "<<index<<"\n";

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