#include<bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<char> arr(n);

        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int zc = 0;
        int oc = 0;

        for(int i=0; i<n-1; i++){
            if(arr[i] == arr[i+1]){
                if(arr[i] == '0'){
                    zc++;
                }
                else{
                    oc++;
                }
            }
        }

        cout<<max(zc,oc)<<"\n";
    }
}