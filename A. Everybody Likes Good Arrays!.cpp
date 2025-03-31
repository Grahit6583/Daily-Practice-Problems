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

        int op=0;
        for(int i=0; i<n-1; i++){
            if(arr[i] % 2 == arr[i+1] % 2){
                op++;
            }
        }

        cout<<op<<"\n";
    }

    return 0;
}
