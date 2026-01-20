#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,k,q;
    cin>>n>>k>>q;
    vector<int> range(200000,0);
    for(int i=0; i<n; i++){
        int l,r;
        cin>>l>>r;
        range[l]++;
        range[r+1]--;
    }

    for(int i=1; i<=200000; i++){
        range[i] += range[i-1];
    }

    for(int i=0; i<=200000; i++){
        if(range[i] >= k){
            range[i] = 1;
        }
        else{
            range[i] = 0;
        }
    }

    for(int i=1; i<=200000; i++){
        range[i] += range[i-1];
    }

    for(int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;
        cout<<range[b]-range[a-1]<<"\n";
    }

    return 0;
}
