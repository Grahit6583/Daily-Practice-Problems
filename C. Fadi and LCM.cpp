#include<bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    cin>>x;

    long long a,b;
    for(long long i=1; i*i<=x; i++){
        if(x%i == 0 && (i * x/i)/__gcd(i,x/i) == x){
            a = i;
            b = x/i;
        }
    }

    cout<<a<<" "<<b;
    return 0;
}