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

        vector<pair<int,int>> ans(n);
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            if(x%k == 0){
                ans[i] = {k,i};
            }
            else{
                ans[i] = {x%k, i};
            }
        }


        sort(ans.begin(),ans.end(),[&] (pair<int,int> a,pair<int,int> b){
            if(a.first != b.first){
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        for(int i=0; i<n; i++){
            cout<<ans[i].second + 1<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
