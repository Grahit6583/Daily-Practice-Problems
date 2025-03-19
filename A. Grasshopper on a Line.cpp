#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int x,k;
        cin>>x>>k;

        if(x<k || x%k != 0){
            cout<<1<<"\n";
            cout<<x<<"\n";
        }
        else{
            cout<<2<<"\n";
            cout<<(k+1)<<" "<<x-(k+1)<<"\n";
        }
    }

    return 0;
}
