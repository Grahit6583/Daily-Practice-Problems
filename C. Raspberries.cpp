#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        
        int mini = INT_MAX;
        // int odd = 0;
        int even = 0;
        if(k == 2 || k == 3 || k == 5){
            for(int i=0; i<n; i++){
                int remain = arr[i] % k;
                if(remain == 0){
                    mini = 0;
                    break;
                }
                int ops = k - remain;
                mini = min(mini, ops);
            }
        }
        else{

            for(int i=0; i<n; i++){
                if(arr[i]%k == 0){
                    mini = 0;
                    break;
                }
                else if(arr[i] % 2 == 0 && arr[i]%k != 0){
                    even++;
                    if(even == 2){
                        mini = 0;
                        break;
                    }
                }
                else if((arr[i]+1) % k == 0){
                    mini = min(mini,1);
                }
            }
        }

        if(mini != INT_MAX){
            cout<<mini<<"\n";
        }
        else{
            if(even == 1)
            {
                cout<<1<<"\n";
            }
            else{
                cout<<2<<"\n";
            }
        }
    }

    return 0;
}
