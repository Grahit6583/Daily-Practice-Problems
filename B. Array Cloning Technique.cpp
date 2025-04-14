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

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            mp[x]++;
        }

        int curr_freq = 0;
        for(auto it : mp){
            curr_freq = max(curr_freq,it.second);
        }

        int op = 0;
        while(curr_freq < n){
            op++;
            if(curr_freq * 2 <= n){
                op += curr_freq;
                curr_freq *= 2;
            }
            else{
                op += n-curr_freq;
                curr_freq = n;
            }
        }

        cout<<op<<"\n";
    }

    return 0;
}
