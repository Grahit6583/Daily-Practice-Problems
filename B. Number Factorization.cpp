#include<bits/stdc++.h>

using namespace std;

int solve(int n){
    map<int,int> mp;
    int x = 1;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            int cnt=0;
            while(n%i == 0){
                n /= i;
                cnt++;
            }
            mp[i] = cnt;
            x = max(x,cnt);
        }
    }
    if(n > 1){
        mp[n] = 1;
    }
    int ans = 0;
    for(int i=1; i<=x; i++){
        int prod = 1;
        for(auto it : mp){
            if(it.second > 0){
                mp[it.first]--;
                prod *= it.first;
            }
        }
        ans += prod;
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        cout<<solve(n)<<"\n";
    }
    return 0;
}