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

        int a = 0;
        int maxi = 0;
        int i=0;
        while(i<n){
            while(s[i] == '<'){
                a++;
                i++;
            }
            maxi = max(maxi,a+1);
            a=0;
            while(s[i] == '>'){
                a++;
                i++;
            }
            maxi = max(maxi,a+1);
            a=0;
        }

        cout<<maxi<<"\n";
    }

    return 0;
}
