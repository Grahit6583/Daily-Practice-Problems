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

        bool flag = false;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(__gcd(arr[i],arr[j]) <= 2){
                    flag = true;
                }
            }
        }

        if(flag){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }

    return 0;
}
