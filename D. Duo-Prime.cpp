#include<bits/stdc++.h>

using namespace std;

bool isPrime(int num){
    for(int i=2; i*i <=num; i++){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}

int main(){

    int n;
    cin>>n;

    vector<int> prime;
    for(int i=2; i<=n; i++){
        if(isPrime(i)){
            prime.push_back(i);
        }
    }

    int cnt = 0;
    for(int k=6; k<=n; k++){
        map<int,int> mp;
        int i = 0;
        int num = k;

        while(num > 0){
            if(prime[i] > num){
                break;
            }

            if(num % prime[i] == 0){
                num = num/prime[i];
                mp[prime[i]]++;
            }
            else{
                i++;
            }
        }

        if(mp.size() == 2){
            cnt++;
        }
    }

    cout<<cnt<<"\n";
    return 0;
}
