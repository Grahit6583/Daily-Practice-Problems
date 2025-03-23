#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        int i=1;
        while(n%i == 0){
            i++;
        }

        cout<<i-1<<"\n";
    }

    return 0;
}
