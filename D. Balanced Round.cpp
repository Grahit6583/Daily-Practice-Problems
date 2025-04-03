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
        
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int cnt = 1;
        int maxi = 1;
        for(int i=0; i<n-1; i++){
            if(abs(arr[i+1]-arr[i]) <= k){
                cnt++;
            }
            else{
                cnt = 1;
            }
            maxi = max(maxi,cnt);
        }

        cout<<n-maxi<<"\n";
    }

    return 0;
}
