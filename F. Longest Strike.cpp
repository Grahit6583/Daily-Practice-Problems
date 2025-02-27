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

        map<int,int> mp;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            mp[x]++;
        }
        
        vector<int> valid;
        for(auto it : mp){
            if(it.second >= k){
                valid.push_back(it.first);
            }
        }
        int x = valid.size();
        if(x == 0){
            cout<<"-1\n";
        }
        else{
            int l=0;
            int r=0;
            int len = 0;
            int first = -1;
            int last = -1;
            while(r<x){
                if(r+1 < x && valid[r] + 1 == valid[r+1]){
                    r++;
                }
                else{
                    if(r-l+1 > len){
                        first = l;
                        last = r;
                        len = r-l+1;
                    }
                    l = r+1;
                    r++;
                }
            }
            
            cout << valid[first] << " " << valid[last] << "\n";
        }
    }
    return 0;
}