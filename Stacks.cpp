#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        vector<int> ans(n,INT_MAX);
        for(int i=0; i<n; i++){
            int index = upper_bound(ans.begin(),ans.end(),arr[i])- ans.begin();
            ans[index] = arr[i];
        }

        vector<int> res;
        for(int i=0; i<n; i++){
            if(ans[i] == INT_MAX){
                break;
            }
            res.push_back(ans[i]);
        }
        
        cout<<res.size()<<" ";
        int k = res.size();
        for(int i=0; i<k; i++){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}