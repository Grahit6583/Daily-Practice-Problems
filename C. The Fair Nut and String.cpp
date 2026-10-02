#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll MOD = 1e9 + 7;

void solve(){
    string s;
    cin>>s;

    string reducedString = "";
    for(char c : s){
        if(c == 'a' || c == 'b'){
            reducedString += c;
        }
    }

    ll  counta = 0;
    ll answer = 1;

    for(char c : reducedString){
        if(c == 'a'){
            counta++;
        }else{
            if(counta > 0){
                answer = ((answer % MOD) * ((counta + 1)%MOD))%MOD;
            }
            counta = 0;
        }
    }

    if(counta > 0){
        answer = ((answer % MOD) * ((counta + 1)%MOD))%MOD;
    }

    answer--;
    cout<<answer;
    return;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

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