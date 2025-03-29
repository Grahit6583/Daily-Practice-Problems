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
        
        vector<int> arr(n);
        int two = 0;

        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(arr[i] == 2){
                two++;
            }
        }

        int cnt = 0;
        int ans = -1;
        for(int i=0; i<n; i++){
            if(arr[i] == 2){
                cnt++;
            }

            if(cnt == two - cnt){
                ans = i+1;
                break;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}
