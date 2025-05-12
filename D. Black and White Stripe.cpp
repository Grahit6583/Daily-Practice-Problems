#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        vector<int> prefix(n+1,0);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + (s[i] == 'W');
        }

        int mini = INT_MAX;
        for(int i=0; i<=n-k; i++){
            mini = min(mini,(prefix[i+k]-prefix[i]));
        }

        cout<<mini<<"\n";
    }

    return 0;
}
