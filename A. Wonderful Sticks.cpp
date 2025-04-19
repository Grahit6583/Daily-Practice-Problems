#include<bits/stdc++.h>

using namespace std;

int find_min(vector<bool> &vis,int n){

    for(int i=0; i<n; i++){
        if(!vis[i]){
            vis[i] = true;
            return i;
        }
    }
    return -1;
}

int find_max(vector<bool> &vis,int n){

    for(int i=n-1; i>=0; i--){
        if(!vis[i]){
            vis[i] = true;
            return i;
        }
    }
    return -1;
}

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

        vector<bool> vis(n+1, false);
        vis[0] = true;

        vector<int> ans(n);
        int l = n-1;
        for(int i=l-1; i>=0; i--){
            if(s[i] == '<'){
                int ind = find_min(vis,n+1);
                ans[i+1] = ind;
            }
            else{
                int ind = find_max(vis,n+1);
                ans[i+1] = ind;
            }
        }

        for(int i=0; i<=n+1; i++){
            if(!vis[i]){
                ans[0] = i;
                break;
            }
        }

        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
