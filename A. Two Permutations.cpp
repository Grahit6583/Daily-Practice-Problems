#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,a,b;
        cin>>n>>a>>b;

        if(a+b+2 <= n || (a==b && a==n)){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }

    return 0;
}
