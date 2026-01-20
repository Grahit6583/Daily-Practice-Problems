#include<bits/stdc++.h>
#define mod 998244353;

using namespace std;



int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long long n,k;
    cin>>n>>k;

    long long ans = 0;
    for(int i=0; i<60; i++){
        if(k&(1LL << i)){
            long long temp = n;
            temp >>=(i+1);
            temp *= (1LL << i);
            temp %= mod;

            if(n & (1LL << i)){
                temp += ((n%(1LL << i))+1);
                temp %= mod;
            }
            ans += temp;
            ans %= mod;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
