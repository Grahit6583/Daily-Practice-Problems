#include<bits/stdc++.h>

using namespace std;

bool isPrime(int num){
    if(num < 2){
        return false;
    }
    for(int i=2; i*i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    cin>>n>>k;

    vector<int> primes;
    for(int i=2; i<=n; i++){
        if(isPrime(i)){
            primes.push_back(i);
        }
    }

    int l = primes.size();
    int cnt = 0;

    for(int i=0; i<l-1; i++){
        int trio = primes[i]+primes[i+1]+1;
        if(trio <= n && isPrime(trio)){
            cnt++;
        }
    }

    if(cnt >= k){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

    return 0;
}
