#include<bits/stdc++.h>

using namespace std;

bool solve(int n){
    int cnt = 0;    
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            while(n % i == 0){
                n /= i;
            }
            cnt++;
        }
    }
    if(n>1){
        cnt++;
    }
    
    return cnt == 2 ? true : false;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n;
    cin>>n;
    
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(solve(i)){
            cnt++;
        }
    }

    cout<<cnt;

    return 0;
}