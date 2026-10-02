#include <bits/stdc++.h>
using namespace std;

long long solve(long long n){
    if(n<=1){
        return 1;
    }

    if(n%2){
        return 1 + solve(3*n + 1);
    }
    else{
        return 1 + solve(n/2);
    }

    return 0;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin>>n;
    cout<<solve(n);

    return 0;
}
