#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long n,k,x;
        cin>>n>>k>>x;

        long long mini, maxi;

        // mini = (k*(k+1))/2;
        // maxi = ((n*(n+1))/2) - (((n-k)*(n-k+1))/2);

        if(x >= (k*(k+1))/2 && x <= ((n*(n+1))/2) - (((n-k)*(n-k+1))/2)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}
