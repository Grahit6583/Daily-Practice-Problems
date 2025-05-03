#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        set<char> st1;
        set<char> st2;
        vector<int> pre(n+1,0);
        vector<int> suff(n+1,0);
        for(int i=0; i<n; i++){
            st1.insert(s[i]);
            st2.insert(s[n-i-1]);
            pre[i] = st1.size();
            suff[n-i-1] = st2.size();
        }

        int ans = 0; 
        for(int i=0; i<n; i++){
            ans = max(ans,pre[i]+suff[i+1]);
        }

        cout<<ans<<"\n";

    }

    return 0;
}
