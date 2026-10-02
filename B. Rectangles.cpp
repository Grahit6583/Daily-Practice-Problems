#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;

    long long a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    long long answer = 0;
    for(int i=0; i<n; i++){
        long long c = 0;
        for(int j=0; j<m; j++){
            c += a[i][j];
        }
        answer += ((1LL<<c)-1);
        answer += ((1LL<<(m-c))-1);
    }

    for(int i=0; i<m; i++){
        long long c = 0;
        for(int j=0; j<n; j++){
            c += a[j][i];
        }

        answer += ((1LL<<(c))-1);
        answer += ((1LL<<(n-c))-1);
    }

    cout<<answer - n*m <<endl;
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
    while(t--){
        solve();
    }

    return 0;
}