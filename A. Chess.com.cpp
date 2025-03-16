#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        char ch;
        int x;
        cin>>ch>>x;

        for(char i='a'; i<='h'; i++){
            if(i == ch){
                continue;
            }

            cout<<i<<x<<"\n";
        }

        for(int i=1; i<=8; i++){
            if(i == x){
                continue;
            }

            cout<<ch<<i<<"\n";
        }
    }

    return 0;
}
