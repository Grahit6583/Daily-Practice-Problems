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

    if(arr[0] != 1){
        cout<<1;
    }
    else{
        long long minSum = 0;
        long long maxSum = 1;

        for(int i=1; i<n; i++){
            long long mini = arr[i] + minSum;
            long long maxi = arr[i] + maxSum;

            if(mini - maxSum > 1){
                break;
            }

            maxSum = max(maxi,maxSum);
        }

        cout<<maxSum+1;
    }

    return 0;
}
