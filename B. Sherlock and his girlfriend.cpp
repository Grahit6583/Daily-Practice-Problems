#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    if(n == 1 || n==2){
        cout<<1<<"\n";
        if(n==1){
            cout<<1;
        }
        else{
            cout<<1<<" "<<1;
        }
    }
    else{
        cout<<2<<"\n";
        for(int i=2; i<=n+1; i++){
            if(isPrime(i)){
                cout<<1<<" ";
            }
            else{
                cout<<2<<" ";
            }
        }
    }


    return 0;
}