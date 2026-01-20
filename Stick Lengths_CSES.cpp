#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n; 
    cin>>n;

    vector<long long> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    long long median = 0;
    if(n%2 == 1){
        median = arr[n/2];
    }
    else{
        median = (arr[n/2] + arr[n/2 - 1])/2;
    }

    long long ans = 0;

    for(int i=0; i<n; i++){
        ans += abs(arr[i]-median);
    }

    cout<<ans;

    return 0;
}
