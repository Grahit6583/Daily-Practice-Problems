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
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(int i=0; i<n; i++){
            if(arr[i] == 1){
                arr[i]++;
            }
        }
        for(int i=0; i<n-1; i++){
            if(arr[i] == 1){
                arr[i]++;
            }

            if(arr[i+1] % arr[i] == 0){
                arr[i+1] += 1;
            }
        }

        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
