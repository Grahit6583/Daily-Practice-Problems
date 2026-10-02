#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool valid(int i, int j, int k, int l){
    int sum = i+k+j+l;
    if((sum%i) == 0 && (sum%j) == 0 && (sum%k) == 0 && (sum%l) == 0){
        return true;
    }
    return false;
}

void solve(){
    int n;
    cin>>n;

    if(n == 1){
        cout<<1<<"\n";
        return;
    }
    if(n==2){
        cout<<-1<<"\n";
        return;
    }

    for(int i=0; i<n; i++){
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}