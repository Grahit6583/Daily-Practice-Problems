#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        string s,t;
        cin>>s>>t;

        int n=s.size();
        int m=t.size();

        vector<int> hash(26,0);
        for(int i=0; i<m; i++){
            hash[t[i]-'A']++;
        }

        for(int i=n-1; i>=0; i--){
            if(hash[s[i]-'A'] > 0){
                hash[s[i]-'A']--;
            }
            else{
                s[i] = '.';
            }
        }

        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i] != '.'){
                ans += s[i];
            }
        }

        if(ans == t){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}
