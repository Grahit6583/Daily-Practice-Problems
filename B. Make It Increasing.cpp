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

        int cnt=0;
        for(int i=n-2; i>=0; i--){
            while(arr[i] >= arr[i+1]){
                cnt++;
                arr[i] /= 2;
                if(arr[i] == 0){
                    break;
                }
            }

            if(arr[i]==0 && arr[i+1]==0){
                cnt=-1;
                break;
            }
        }
        cout<<cnt<<"\n";
    }

    return 0;
}
