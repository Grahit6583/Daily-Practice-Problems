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
        
        bool flag = false;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            if(x == k && flag == false){
                flag = true;
            }
        }

        if(flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}
