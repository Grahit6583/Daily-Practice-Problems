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

    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i] - 1;
    }

    cout<<sum;

    return 0;
}
