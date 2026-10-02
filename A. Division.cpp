#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(){
    ll p,q;
    cin>>p>>q;

    vector<int>primes;
    ll nq = q;
    for(int i=2; i*i<=nq; i++){
        if(nq%i == 0){
            primes.push_back(i);
            while(nq%i == 0){
                nq /= i;
            }
        }
    }
    if(nq>1){
        primes.push_back(nq);
    }

    ll ans = p;
    for(auto prime:primes){
        ll a=0,b=0;
        ll nq=q, np=p;
        while(nq%prime == 0){
            nq /= prime;
            a++;
        }
        while(np%prime == 0){
            np /= prime;
            b++;
        }

        ll drop = b-a+1;
        ll val=1;
        for(int i=0; i<drop; i++){
            val *= prime;
        }

        ans = min(ans,val);
    }
    cout<<p/ans<<"\n";
}

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
        solve();
    }
}