#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long a,b;
        cin>>a>>b;

        if(a>b){
            swap(a,b);
        }

        if(a==b){
            cout<<0<<" "<<0<<"\n";
        }
        else{
            long long gcd = b-a;
            long long ans = min(a%gcd, gcd - a % gcd);
            cout<<gcd<<" "<<ans<<"\n";
        }
    }

    return 0;
}
