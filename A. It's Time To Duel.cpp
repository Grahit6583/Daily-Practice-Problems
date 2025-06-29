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
        int cnt = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(arr[i] == 1){
                cnt++;
            }
        }

        bool flag = true;
        for(int i=n-1; i>=1; i--){
            if(arr[i] == 0 && arr[i-1] == 0){
                flag = false;
                break;
            }
        }

        if(flag && cnt != n){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}
