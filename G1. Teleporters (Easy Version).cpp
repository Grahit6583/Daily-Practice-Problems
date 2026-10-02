#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
            arr[i] += (i+1);
        }
        
        sort(arr.begin(),arr.end());
        
        int ans = 0;
        int sum = 0;

        for(int i=0; i<n; i++){
            if(sum+arr[i] <= c){
                ans++;
                sum += arr[i];
            }
            else{
                break;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}
