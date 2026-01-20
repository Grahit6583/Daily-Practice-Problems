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

        vector<int> arr(n,0);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        vector<int> cnt(31,0);

        for(int i=30; i>=0; i--){
            int temp=0;
            for(int j=0; j<n; j++){
                if((arr[j] & (1<<i)) > 0){
                    temp++;
                }
            }
            cnt[i] = n-temp;
        }
        int ans = 0;
        for(int i=30; i>=0; i--){
            if(cnt[i] <= k){
                k -= cnt[i];
                ans |= (1<<i);
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}
