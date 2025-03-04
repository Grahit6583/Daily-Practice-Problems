#include<bits/stdc++.h>

using namespace std;

int main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++){
            char ch;
            cin>>ch;
            mp[ch]++;
        }
        int cnt = 0;
        for(auto it : mp){
            if(it.second % 2 == 1){
                cnt++;
            }
        }

        if(cnt <= k+1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0; 
}