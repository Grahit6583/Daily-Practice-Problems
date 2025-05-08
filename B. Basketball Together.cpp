#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

        int n,d;
        cin>>n>>d;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        sort(arr.begin(),arr.end());

        int l=-1;
        int r=n-1;
        int maxi = 1;
        int team=0;

        while(l<r){
            if((arr[r]*maxi) <= d && l < r){
                l++;
                maxi++;
            }
            else{
                maxi=1;
                r--;
                team++;
            }
        }

        cout<<team<<"\n";

    return 0;
}
