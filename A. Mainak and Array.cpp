#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int ans = arr[n-1]-arr[0];

        for(int i=1; i<n; i++){
            ans = max(ans,arr[i]-arr[0]);
        }

        for(int i=0; i<n-1; i++){
            ans = max(ans, arr[n-1]-arr[i]);
        }

        for(int i=0; i<n-1; i++){
            ans = max(ans,arr[i]-arr[i+1]);
        }

        cout<<ans<<"\n";
    }

    return 0;
}
