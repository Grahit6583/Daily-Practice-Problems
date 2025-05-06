#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n;
        char c;

        cin>>n>>c;

        string s;
        cin>>s;
        s += s;
        n *= 2;
        int ind = -1;
        int ans = INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'g'){
                ind = i;
            }
            if(s[i] == c){
                ans = max(ans, ind-i);
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}
