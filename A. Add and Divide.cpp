#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t; 
    cin>>t;

    while(t--){
        long long a,b;
        cin>>a>>b;

        long long ans = INT_MAX;
        for(int add=0; add<=31; add++){
            long long op = add;
            long long new_b = b + add;
            if(new_b == 1){
                continue;
            }

            long long copy_a = a;
            while(copy_a > 0){
                copy_a /= new_b;
                op++;
            }

            ans = min(ans,op);
        }

        cout<<ans<<"\n";
    }

    return 0;
}
