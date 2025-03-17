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

        int odd_cnt=0;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            if(x % 2 != 0){
                odd_cnt++;
            }
        }

        if(odd_cnt % 2 == 1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }

    return 0;
}
