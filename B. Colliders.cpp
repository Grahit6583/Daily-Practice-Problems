#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 100001;
int spf[N], occupied[N], isActive[N];

void sieve(){
    for(int i=1; i<N; i++){
        spf[i] = i;
    }

    for(int i=2; i<N; i++){
        for(int j=2*i; j<N; j+=i){
            if(spf[j] == j){
                spf[j] = i;
            }
        }
    }
}

vector<int> primeFactor(int n){
    vector<int> prime;
    while (n != 1)
    {
        int x = spf[n];
        prime.push_back(x);
        while(n%x == 0){
            n/=x;
        }
    }
    return prime;
}

void solve(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        char c;
        cin>>c;

        int x;
        cin>>x;
        vector<int> primes = primeFactor(x);
        if(c == '+'){
            if(isActive[x]){
                cout<<"Already on\n";
            }else{
                int collision = 0;
                for(auto j : primes){
                    if(occupied[j]){
                        collision = occupied[j];
                    }
                }
                if(collision){
                    cout<<"Conflict with "<<collision<<"\n";
                }else{
                    cout<<"Success\n";
                    for(auto j : primes){
                        occupied[j] = x;
                    }
                    isActive[x] = 1;
                }
            }
        }else{
            if(!isActive[x]){
                cout<<"Already off\n";
            }else{
                cout<<"Success\n";
                isActive[x] = 0;
                for(auto j : primes){
                    occupied[j] = 0;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    sieve();
    while(t--){
        solve();
    }

    return 0;
}