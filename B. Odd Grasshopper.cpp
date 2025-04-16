#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long x,n;
        cin>>x>>n;

        long long pos = 0;
            if(n%4 == 0){
                pos = 0;
            }
            else if(n%4 == 1){
                pos = -n;
            }
            else if(n%4 == 2){
                pos = 1;
            }
            else if(n%4 == 3){
                pos = n+1;
            }

        if(x%2 == 0){
            cout<<x+pos<<"\n";
        }
        else{
            cout<<x-pos<<"\n";
        }
    }

    return 0;
}
