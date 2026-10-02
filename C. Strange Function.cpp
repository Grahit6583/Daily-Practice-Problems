#include<bits/stdc++.h>

using namespace std;
int M = 1e9+7;
typedef long long ll;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll ans = 0;
        ll g=1;
        for(ll i=1; g<=n; i++){
            g = (g*i)/__gcd(g,i);
            if(g > n){
                break;
            }
            ans += n/g;
        }
        cout<<(ans+n)%M<<"\n";
    }
}