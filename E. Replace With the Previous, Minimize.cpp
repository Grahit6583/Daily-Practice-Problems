#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    char maxPossiblechar = 'a';
    char notPossiblechar = 'a';

    bool found = false;

    for(int i = 0; i < n; i++){
        if(s[i] - 'a' > k){
            notPossiblechar = s[i];
            found = true;
            break;
        }

        if(s[i] > maxPossiblechar){
            maxPossiblechar = s[i];
        }
    }

    ll oprUsed = maxPossiblechar - 'a';
    ll oprLeft = k - oprUsed;

    // All characters in [a, maxPossiblechar] become 'a'
    for(int i = 0; i < n; i++){
        if(s[i] <= maxPossiblechar){
            s[i] = 'a';
        }
    }

    // If we found a character that cannot reach 'a'
    if(found){

        char newNotPossiblechar = notPossiblechar - oprLeft;

        for(int i = 0; i < n; i++){

            // Only this range is affected
            if(s[i] >= newNotPossiblechar &&
               s[i] <= notPossiblechar){

                s[i] = newNotPossiblechar;
            }
        }
    }

    cout << s << endl;
    return;
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