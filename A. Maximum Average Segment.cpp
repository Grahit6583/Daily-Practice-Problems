#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

ld maxSubarray(vector<ld> &arr, int d, int n){
    vector<ld> prefix(n);
    prefix[0] = arr[0];
    for(int i=1; i<n; i++){
        prefix[i] = arr[i] + prefix[i-1];
    }

    ld ans = -1e18;
    ld minSofar = 0;
    for(int i=d-1; i<n; i++){
        ld SubarraySum = prefix[i] - minSofar;
        minSofar = min(minSofar, prefix[i-d+1]);
        ans = max(ans,SubarraySum);
    }

    return ans;
}

bool f(ld x, vector<ld> &arr, int d, int n){
    vector<ld> transformed(n);
    for(int i=0; i<n; i++){
        transformed[i] = arr[i]-x;
    }

    return maxSubarray(transformed,d,n) >= 0;
}

pair<int,int> maxSubarraysum(vector<ld> &arr, int d, int n){
    vector<ld> prefix(n);
    prefix[0] = arr[0];
    for(int i=1; i<n; i++){
        prefix[i] = arr[i] + prefix[i-1];
    }

    ld ans = -1e18;
    ld minSofar = 0;
    int bestLeftindex = -1;
    for(int i=d-1; i<n; i++){
        ld SubarraySum = prefix[i] - minSofar;
        ans = max(ans,SubarraySum);
        if(ans >= 0){
            return {bestLeftindex + 1,i};
        }
        if(minSofar > prefix[i-d+1]){
            minSofar = prefix[i-d+1];
            bestLeftindex = i-d+1;
        }
        
    }

    return {-10,10};
}

pair<int,int> bestSubarray(ld x, vector<ld> &arr, int d, int n){
    vector<ld> transformed(n);
    for(int i=0; i<n; i++){
        transformed[i] = arr[i]-x;
    }

    return maxSubarraysum(transformed,d,n);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin>>n>>d;

    vector<ld> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    ld low = 0, high = 100;

    int iterations = 100;

    for(int i=1; i<=iterations; i++){
        ld mid = (low + high)/2;
        if(f(mid,arr,d,n)){
            low = mid;
        }
        else{
            high = mid;
        }
    }

    pair<int,int> ans = bestSubarray(low,arr,d,n);
    cout<<ans.first + 1<<" "<<ans.second + 1<<endl;
    return 0;
}