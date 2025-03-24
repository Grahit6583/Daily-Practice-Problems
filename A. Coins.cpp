#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long n,k;
        cin>>n>>k;

        if((n-k) % 2 == 0){
            cout<<"Yes\n";
        }
        else{
            if(n%2 ==1 && k%2 == 0){
                cout<<"No\n";
            }
            else{
                cout<<"Yes\n";
            }
        }
    }

    return 0;
}
