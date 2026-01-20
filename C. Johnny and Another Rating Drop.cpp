#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;
        long long c = n;
        long long bits_cnt = 0;
        while(n>0){
            bits_cnt++;
            n >>= 1;
        }

        long long ans = 0;
        long long d=1;
        while(bits_cnt--){
            ans += (c/d);
            d *= 2;
        }

        cout<<ans<<"\n";
    }

    return 0;
}
