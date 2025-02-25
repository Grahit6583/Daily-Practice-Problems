#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    
    unordered_map<int,int> mp;
    int start = 0, ans = 0;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;

        if(mp.contains(t)){
            start = max(start, mp[t] + 1);
        }

        mp[t] = i;
        ans = max(ans, i-start+1);
    }

    cout<<ans;
    return 0;
}