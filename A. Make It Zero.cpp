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
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
        }

        if(n%2 == 0){
            cout<<2<<"\n";
            cout<<1<<" "<<n<<"\n";
            cout<<1<<" "<<n<<"\n";
        }
        else{
            cout<<4<<"\n";
            cout<<1<<" "<<n-1<<"\n";
            cout<<1<<" "<<n-1<<"\n";
            cout<<n-1<<" "<<n<<"\n";
            cout<<n-1<<" "<<n<<"\n";
        }
    }

    return 0;
}
