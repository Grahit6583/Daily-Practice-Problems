#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int a,b,n;
        cin>>a>>b>>n;

        long long maxi =  b;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            maxi += min(x,a-1);
        }

        cout<<maxi<<"\n";
    }

    return 0;
}
