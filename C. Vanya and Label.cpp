#include<bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    map<char,int> mp;
    int cnt = 0;
    for(char c='0'; c<='9'; c++){
        mp[c] = cnt;
        cnt++;
    }

    for(char c='A'; c<='Z'; c++){
        mp[c] = cnt;
        cnt++;
    }

    for(char c='a'; c<='z'; c++){
        mp[c] = cnt;
        cnt++;
    }

    mp['-'] = 62;
    mp['_'] = 63;
    string s;
    cin>>s;
    int n = s.length();

    int zero = 0;

    for(int j=0; j<n; j++){
        int ones =  __builtin_popcount(mp[s[j]]);
        zero += (6-ones);
    }

    long long ans = 1;

    for(int i=0; i<zero; i++){
        ans = (ans*3)%mod;
    }

    cout<<ans;

    return 0;
}
