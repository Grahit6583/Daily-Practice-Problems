#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        vector<bool> ocurr(26,false);
        int sum = 0;
        for(int i=0; i<n; i++){
            if(!ocurr[s[i]-'a']){
                sum += n-i;
                ocurr[s[i]-'a'] = true;
            }
        }

        cout<<sum<<"\n";
    }

    return 0;
}