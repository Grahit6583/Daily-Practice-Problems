#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<long long> vec(n*k);
        for(int i=0; i<n*k; i++){
            cin>>vec[i];
        }

        long long pointer = n*k;
        long long sum =0;
        while(k--){
            pointer -= (n/2+1);
            sum += vec[pointer];
        }

        cout<<sum<<"\n";
    }

    return 0;
}
