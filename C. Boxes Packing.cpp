#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> arr(n);
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    
    int maxi = INT_MIN;

    for(auto it : mp){
        maxi = max(maxi,it.second);
    }

    cout<<maxi<<endl;

    return 0;
}