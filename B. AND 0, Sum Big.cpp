#include<bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

long long power(int n, int k){
    if(k==0){
        return 1;
    }

    long long ans = power(n,k-1);
    ans %= mod;
    ans *= n;
    ans %= mod;

    return ans;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        cout<<power(n,k)<<"\n";
    }

    return 0;
}
