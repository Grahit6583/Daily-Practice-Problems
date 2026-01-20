#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    long long n,c;
    cin>>n>>c;

    vector<long long> start(n),end(n),cost(n);
    for(int i=0; i<n; i++){
        cin>>start[i]>>end[i]>>cost[i];
    }

    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(start[i]);
        st.insert(end[i]+1);
    }

    int ind = 0;
    map<int,int> mp;
    for(auto it : st){
        mp[it] = ind;
        ind++;
    }

    vector<long long> diff(ind+1,0);

    for(int i=0; i<n; i++){
        diff[mp[start[i]]] += cost[i];
        diff[mp[end[i]+1]] -= cost[i];
    }

    for(int i=1; i<ind+1; i++){
        diff[i] += diff[i-1];
    }
    vector<int> a(st.begin(),st.end());
    long long ans = 0;
    int l = a.size();
    for(int i=1; i<l; i++){
        long long span = a[i]-a[i-1];
        ans += (min(diff[i-1],c) * span);
    }
    cout<<ans;
    return 0;
}
