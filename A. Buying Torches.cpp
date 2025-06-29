#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        long long x,y,k;
        cin>>x>>y>>k;

        long long total_sticks = y*k + k-1;
        long long sticks = (total_sticks+(x-1)-1)/(x-1);
        cout<<sticks+k<<"\n"; 
    }
    return 0;
}
