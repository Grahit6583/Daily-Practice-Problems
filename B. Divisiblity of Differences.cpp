#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k,m;
    cin>>n>>k>>m;

    vector<int> arr(n);
    map<int,vector<int>> mp;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        mp[(arr[i]%m)].push_back(arr[i]);
    }

    vector<int> ans;
    for(auto it : mp){
        int s = it.second.size();
        if(s >= k){
            ans = it.second;
            break;
        }
    }
    if(ans.size() == 0){
        cout<<"No";
        return;
    }

    cout<<"Yes\n";
    for(int i=0; i<k; i++){
        cout<<ans[i]<<" ";
    }
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t=1;

	while(t--){
	    solve();
	}
	return 0;
}
