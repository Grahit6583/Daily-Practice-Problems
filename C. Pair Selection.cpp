#include<bits/stdc++.h>

using namespace std;

typedef long double lld;

bool solve(lld x, vector<lld>&a, vector<lld> &b, int n, int k){
    vector<lld> transform(n);
    for(int i=0; i<n; i++){
        transform[i] = a[i]-b[i]*x;
    }

    sort(transform.begin(),transform.end());
    reverse(transform.begin(),transform.end());
    lld sum = 0;
    for(int i=0; i<k; i++){
        sum += transform[i];
    }
    
    return sum >= 0;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;

    vector<lld> a(n),b(n);
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
    }

    lld low = 0;
    lld high = 1e10;

    for(int i=0; i<60; i++){
        lld mid  = low + (high-low)/2;

        if(solve(mid,a,b,n,k)){
            low = mid;
        }else{
            high = mid;
        }
    }

    cout<<setprecision(7)<<fixed<<low<<endl;
}