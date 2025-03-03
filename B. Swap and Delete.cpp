#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int n = s.size();
        int zero = 0;
        int one = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                zero++;
            }
            else{
                one++;
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(zero > 0 && s[i] == '1'){
                zero--;
            }
            else if(zero == 0 && s[i] == '1'){
                ans = n-i;
                break;
            }
            else if(one > 0 && s[i] == '0'){
                one--;
            }
            else if(one == 0 && s[i] == '0'){
                ans = n-i;
                break;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}