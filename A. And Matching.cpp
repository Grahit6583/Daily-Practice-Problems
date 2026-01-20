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

        if(k == 3 && n == 4){
            cout<<"-1\n";
            continue;
        }
        if(k == 0){
            for(int i=0; i<n/2; i++){
                cout<<i<<" "<<n-i-1<<"\n";
            }
        }
        else if(k==n-1){
            cout<<n-1<<" "<<n-2<<"\n";
            cout<<n-3<<" "<<1<<"\n";
            cout<<2<<" "<<0<<"\n";
            for(int i=3; i<n/2; i++){
                cout<<i<<" "<<n-i-1<<"\n";
            }
        }
        else{
            int a = 0;
            int b = k;
            int c = n-1;
            int d = n-k-1;
            cout<<b<<" "<<c<<"\n";
            cout<<a<<" "<<d<<"\n";
            for(int i=0; i<n/2; i++){
                if(i==a || i==b || i==c || i==d){
                    continue;
                }
                cout<<i<<" "<<n-i-1<<"\n";
            }
        }
    }

    return 0;
}
