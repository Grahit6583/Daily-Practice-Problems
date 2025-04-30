#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long n,k,q;
        cin>>n>>k>>q;

        long long i=0;
        long long cnt = 0;
        long long j;
        for(j=0; j<n; j++){
            int x;
            cin>>x;
            if(q < x){
                if(k <= i){
                    cnt += ((i-k+1)*(i-k+2))/2;
                }
                i=0;
            }
            else{
                i++;
            }
        }
        if(k <= i){
            cnt += ((i-k+1)*(i-k+2))/2;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
