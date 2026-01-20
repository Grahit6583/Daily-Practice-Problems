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
    
        vector<int> arr(n,0);
    
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        vector<int> need(n,0);
        for(int j=0; j<30; j++){
            bool found = 0;
            for(int i=0; i<n; i++){
                if((arr[i]&(1<<j)) && found == 0){
                    found = 1;
                }
                else if(found && (arr[i]&(1<<j)) == 0){
                    need[i] += (1<<j);
                }
            }
        }
    
        for(int i=0; i<n; i++){
            cout<<need[i]<<" ";
        }
    
        cout<<"\n";
    }

    return 0;
}
