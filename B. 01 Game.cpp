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
                one++;
            }
            else{
                zero++;
            }
        }

        int ans = min(zero,one);

        if(ans%2 == 1){
            cout<<"DA\n";
        }
        else{
            cout<<"NET\n";
        }
    }

    return 0;
}
