#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool isPalin(string &s){
    int i=0;
    int j=(int)s.size()-1;

    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &x : s) cin >> x;

    for (auto &x : s){
        if ((int)x.size() == 1 || isPalin(x)){
            cout << "YES\n";
            return;
        }
    }

    map<string,int> mpRev;    // reverse(x) for every string seen so far
    map<string,int> mpCaseB;  // ONLY x[1]+x[0] for length-3 strings

    for (auto &x : s){
        // Case A: x equals reverse of an earlier same-length string
        if (mpRev.count(x)) { cout << "YES\n"; return; }

        // Case B: length-2 x matches a saved length-3 boundary key
        if ((int)x.size() == 2 && mpCaseB.count(x)) { cout << "YES\n"; return; }

        // Case C: length-3 x checked against reverse of an earlier length-2 string
        if ((int)x.size() == 3){
            string t; t += x[1]; t += x[2];
            if (mpRev.count(t)) { cout << "YES\n"; return; }

            string key; key += x[1]; key += x[0];
            mpCaseB[key]++;
        }

        string r = x;
        reverse(r.begin(), r.end());
        mpRev[r]++;
    }

    cout << "NO\n";
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