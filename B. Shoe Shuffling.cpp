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

        int l=0; 
        int r=0;
        bool flag = true;
        vector<int> ans(n);
        int i=0; 

        while(r<n){
            int cnt = 0;
            while(r<n && arr[l] == arr[r]){
                cnt++;
                r++;
            }
            if(cnt == 1){
                flag = false;
                break;
            }

            if(cnt%2 != 0){
                ans[i] = r-1;
                i++;
                for(int j=l; j<r-1; j++){
                    ans[i] = j;
                    i++;
                }
            }
            else{
                for(int j=r-1; j>=l; j--){
                    ans[i] = j;
                    i++;
                }
            }
            l=r;
        }

        if(!flag){
            cout<<-1<<"\n";
        }
        else{
            for(int i=0; i<n; i++){
                cout<<ans[i]+1<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
