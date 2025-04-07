#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        vector<long long> prefix_sum(n);
        prefix_sum[0] = arr[0];
        for(int i=1; i<n; i++){
            prefix_sum[i] = prefix_sum[i-1] + arr[i];
        }
        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            l--;
            r--;
            bool flag = false;
            long long total = prefix_sum[n-1];
            long long segment_sum;
            if(l-1 < 0){
                segment_sum = prefix_sum[r];
            }
            else{
                segment_sum = prefix_sum[r] - prefix_sum[l-1];
            }
            long long ans = total - segment_sum + ((r-l+1)*k);
            // cout<<ans<<"\n";
            if(ans % 2 != 0){
                flag = true;
            }
    
            if(flag){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }

    return 0;
}
