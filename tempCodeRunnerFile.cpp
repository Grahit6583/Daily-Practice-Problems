#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());
    
    int cnt = 0;
    for(int i=0; i<n-1; i++){
        if(arr[i] < arr[i+1]){
            cnt++;
        }
    }

    cout<<n-cnt<<endl;

    return 0;
}