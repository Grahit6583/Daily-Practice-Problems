#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long n,x,y;
        cin>>n>>x>>y;

        long long sum = 0;
        vector<long long> arr(n,0);
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sum += arr[i];
        }

        if((sum+x+y)%2 == 1){
            cout<<"Bob\n";
        }
        else{
            cout<<"Alice\n";
        }
    }

    return 0;
}
