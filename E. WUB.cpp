#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    string s;
    cin>>s;
    int n = s.length();
    string ans = "";
    bool space = false;
    for(int i=0; i<n; i++){
        if(i+2 < n && s.substr(i,3)== "WUB"){
            if(!ans.empty() && space){
                ans += " ";
            }
            i += 2;
            space = false;
        }
        else{
            ans += s[i];
            space = true;
        }
    }

    cout<<"\n"<<ans<<"\n";

    return 0;
}
