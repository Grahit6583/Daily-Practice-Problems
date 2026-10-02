#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<bool> prime(1001, true);

void seive(){
    prime[0] = prime[1] = false;
    for(int i=2; i<=1000; i++){
        if(prime[i]){
            for(int j=i*i; j<=1000; j+=i){
                prime[j] = false;
            }
        }
    }
}

ll powers(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1){
            res = res*a;
        }
        a = a*a;
        b>>=1;
    }
    return res;
}


void solve(){
    int n;
    cin>>n;

    vector<int> arr;
    for(int i=2; i<=n; i++){
        if(prime[i]){
            for(int j=1; j<=n; j++){
                int num = powers(i,j);
                if(num <= n){
                    arr.push_back(num);
                }else{
                    break;
                }
            }
        }
    }
    cout<<arr.size()<<"\n";
    for(auto it : arr){
        cout<<it<<" ";
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    seive();
    while(t--){
        solve();
    }

    return 0;
}