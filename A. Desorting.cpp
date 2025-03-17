#include<bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int mini = INT_MAX;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        bool flag = false;
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                flag = true;
                break;
            }
            else{
                mini = min(mini, arr[i+1]-arr[i]);
            }
        }

        if(flag){
            cout<<0<<"\n";
        }
        else{
            cout<<(mini/2) + 1<<"\n";
        }
    }

    return 0;
}
