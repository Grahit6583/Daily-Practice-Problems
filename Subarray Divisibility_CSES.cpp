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
    map<long long, long long> mp;
    mp[0]=1;
    long long p_sum = 0;
    for(int i=0; i<n; i++){
        p_sum += arr[i];
        mp[(p_sum % n + n)%n]++;
    }

    long long cnt = 0;

    for(auto it : mp){
        long long t = it.second;
        cnt += (t*(t-1)/2);
    }

    cout<<cnt;

    return 0;
}
