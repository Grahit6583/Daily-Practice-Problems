#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        if(n > m || (m%2 == 1 && n%2 == 0)){
            cout<<"No\n";
        }
        else{
            if(n&1){
                int k = m-n+1;
                cout<<"Yes\n";
                for(int i=0; i<n-1; i++){
                    cout<<1<<" ";
                }
                cout<<k<<"\n";
            }
            else{
                int k = (m-n+2)/2;
                cout<<"Yes\n";
                for(int i=0; i<n-2; i++){
                    cout<<1<<" ";
                }
                cout<<k<<" "<<k<<"\n";
            }
        }
    }

    return 0;
}
