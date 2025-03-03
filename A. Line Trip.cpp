#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int max_dis = arr[0];
        for(int i=1; i<n; i++){
            max_dis = max(max_dis, arr[i]-arr[i-1]);
        }

        max_dis = max(max_dis, 2*(x-arr[n-1]));

        cout<<max_dis<<"\n";
    }

    return 0;
}