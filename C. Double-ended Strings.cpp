#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        string b;
        cin>>b;

        int n = s.size();
        int m = b.size();

        int lcs = 0;
        
        for(int len=1; len<= min(n,m); len++){
            for(int i=0; i+len <= n; i++){
                for(int j=0; j+len <= m; j++){
                    string extract = s.substr(i,len);
                    string d = b.substr(j,len);

                    if(extract == d){
                        lcs  = max(lcs,len);
                    }
                }
            }
        }

        int operations = n+m-2*lcs;
        cout<<operations<<"\n"; 
    }
    
    return 0;
}
