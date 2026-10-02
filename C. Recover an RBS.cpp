#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool checkRBS(string &s){
    int n = s.size();

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            cnt++;
        }else{
            cnt--;
        }

        if(cnt<0){
            return false;
        }
    }

    return cnt == 0;
}

void solve(){
    string s;
    cin>>s;

    vector<int> pos;
    ll n = s.size();
    ll op = n/2;
    ll cl = n/2;
    for(int i=0; i<n; i++){
        if(s[i] == '?'){
            pos.push_back(i);
        }
        if(s[i] == '('){
            op--;
        }else if(s[i] == ')'){
            cl--;
        }
    }

    for(int i=0; i<(int)pos.size(); i++){
        if(i<op){
            s[pos[i]] = '(';
        }else{
            s[pos[i]] = ')';
        }
    }

    bool ok = true;
    if(op > 0 && cl > 0){
        swap(s[pos[op-1]],s[pos[op]]);

        if(checkRBS(s)){
            ok = false;
        }
    }

    cout<<(ok ? "YES\n" : "NO\n");
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}