#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,k;
    cin>>n>>k;

    if(k>n){
        cout<<"NO\n";
    }
    else{
        vector<int> ans;
        for(int i=0; i<32; i++){
            if(n&(1<<i)){
                ans.push_back(1<<i);
            }
        }
        int s = ans.size();
        if(k<s){
            cout<<"NO\n";
        }
        else{
            int i=0;
            while(s<k){
                while(ans[i] == 1){
                    i++;
                }
                ans[i] /= 2;
                ans.push_back(ans[i]);
                s++;
            }
            cout<<"YES\n";
            for(int i=0; i<s; i++){
                cout<<ans[i]<<" ";
            }
        }
    }
    return 0;
}
