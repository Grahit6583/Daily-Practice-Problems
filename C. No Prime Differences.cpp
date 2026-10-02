#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int>(m,0));
    int cnt=1;
    for(int i=1; i<n; i+=2){
        for(int j=0; j<m; j++){
            arr[i][j] = cnt;
            cnt++;
        }
    }

    for(int i=0; i<n; i+=2){
        for(int j=0; j<m; j++){
            arr[i][j] = cnt;
            cnt++;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}