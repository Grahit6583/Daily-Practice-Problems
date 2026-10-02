#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const ll MOD = 1e9+7;
const ll N = 1e6;

ll mod(ll a, ll m = MOD){
    return a%m;
}

template <class T> class Math{
    public:
        vector<T> fact, infact;

        Math(){}
        Math(int n){
            fact.resize(n);
            infact.resize(n);
            fact[0] = infact[0] = 1;
            for(int i=1; i<n; i++){
                fact[i] = mod(i*fact[i-1]);
                infact[i] = modinv(fact[i]);
            }
        }

        T modinv(T x, T m=MOD){
            return expo(x,m-2,m);
        }

        T expo(T base, T exp, T m=MOD){
            T res = 1;
            while(exp){
                if(exp & 1){
                    res = mod(res * base, m);
                }
                base  = mod(base*base,m);
                exp >>= 1;
            }
            return res;
        }

        T choose(T n, T k){
            if(k < 0 || k > n){
                return 0;
            }

            T ans = fact[n];
            ans = mod(ans * infact[n-k]);
            ans = mod(ans * infact[k]);
            return ans;
        }

};

void solve(){
    ll n;
    cin>>n;
    ll ans =0;
    Math<ll> m(N);

    for(int i=0; i<=n-1; i++){
        ans = (ans + 2*m.choose(i+n-1,i))%MOD;
    }

    cout<<(ans-n+MOD)%MOD<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}