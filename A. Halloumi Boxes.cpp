#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        if(k == 1){
            bool flag = true;
            for(int i=0; i<n-1; i++){
                if(arr[i] > arr[i+1]){
                    flag = false;
                    break;
                }
            }

            if(flag == false){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }
        else{
            cout<<"YES\n";
        }
    }

    return 0;
}