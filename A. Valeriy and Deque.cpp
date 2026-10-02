#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,q;
    cin>>n>>q;

    deque<long long> dq;
    
    for(int i=0; i<n; i++){
        long long t;
        cin>>t;
        dq.push_back(t);
    }
    
    vector<long long> queries(q);
    for(int i=0; i<q; i++){
        cin>>queries[i];
    }

    vector<pair<long long,long long>> on;
    vector<long long> n2n;
    
    for(int i=0; i<n-1; i++){
        long long a = dq.front();
        dq.pop_front();
        long long b = dq.front();
        dq.pop_front();

        on.push_back({a,b});
        
        long long mini = min(a,b);
        long long maxi = max(a,b);
        
        dq.push_back(mini);
        dq.push_front(maxi);
    }
    
    long long mx = dq.front();
    dq.pop_front();

    while(!dq.empty()){
        n2n.push_back(dq.front());
        dq.pop_front();
    }

    vector<pair<long long,long long>> ans;
    
    for(int i=0; i<q; i++){
        if(queries[i] <= n-1){
            ans.push_back(on[queries[i]-1]);
        }
        else{
            long long ind = (queries[i] - (n-1) - 1) % (n-1);
            ans.push_back({mx, n2n[ind]});
        }
    }

    for(auto it : ans){
        cout<<it.first<<" "<<it.second<<"\n";
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

    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}