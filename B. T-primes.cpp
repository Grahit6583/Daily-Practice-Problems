#include<bits/stdc++.h>

using namespace std;

int N = 1000007;
vector<bool> prime(N,true);

bool isPerfectSquare(long long n) {
    long long root = sqrt(n);
    return (root * root == n) && prime[root];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    prime[0] = prime[1] = false;
    for(long long i=2;i*i<N;i++){
        if(prime[i] != 0){
            for(int j=i*i;j<N;j+=i){
                if(prime[j]){
                    prime[j] = false;
                }
            }
        }
    }
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        long long t;
        cin>>t;
        if(isPerfectSquare(t)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}