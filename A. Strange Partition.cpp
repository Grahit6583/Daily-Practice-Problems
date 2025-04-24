#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n>>x;

        long long a=0,b=0;
        for(int i=0; i<n; i++){
            int t;
            cin>>t;
            a += t;
            b += ceil((double)t/x);
        }
        a = ceil((double)a/x);
        cout<<min(a,b)<<" "<<max(a,b)<<"\n";
    }

    return 0;
}
