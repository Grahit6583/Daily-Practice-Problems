#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    string s;
    cin>>s;

    int n = s.length();
    string temp = "hello";
    int j=0;
    for(int i=0; i<n; i++){
        if(s[i] == temp[j]){
            j++;
            if(j==5){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}