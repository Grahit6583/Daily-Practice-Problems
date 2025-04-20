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
        int x;
        cin>>x;
        int total = x;

        for(int i=1; i<n; i++){
            int y;
            cin>>y;
            total &= y; 
        }

        cout<<total<<"\n";
    }

    return 0;
}
