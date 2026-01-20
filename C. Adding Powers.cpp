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

        vector<long long> arr(n,0);
        long long maxi = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            maxi = max(maxi,arr[i]);
        }
        bool ans = false;
        long long p = 1;
        while(p < maxi){
            p *= k;
        }
        while(p > 0){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(arr[j] >= p){
                    arr[j] -= p;
                    cnt++;                }
            }
            if(cnt > 1){
                ans = true;
                break;
            }

            p /= k;
        }

        if(ans){
            cout<<"No\n";
            continue;
        }
        long long x = *max_element(arr.begin(),arr.end());
        if(x == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}
