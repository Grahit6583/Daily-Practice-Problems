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

        int ele = arr[0];
        bool flag = true;
        for(int i=1; i<n; i++){
            if(ele != arr[i]){
                flag = false;
                break;
            }
        }

        if(flag){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            int ind = -1;
            int maxi = -1;
            for(int i=0; i<n; i++){
                if(maxi < arr[i]){
                    maxi = arr[i];
                    ind = i;
                }
            }
            swap(arr[0],arr[ind]);
            for(int i=0; i<n; i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
