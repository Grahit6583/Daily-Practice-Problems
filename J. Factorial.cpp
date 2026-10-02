#include <bits/stdc++.h>
using namespace std;

long long solve(long long n){
    if(n<=0){
        return 1;
    }

    return n * solve(n-1);
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
