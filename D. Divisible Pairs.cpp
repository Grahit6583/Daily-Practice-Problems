#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,x,y;
        cin>>n>>x>>y;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        long long cnt = 0;
        map<pair<int,int>,int> mp;

        for(int i=0; i<n; i++){
            int xMod = (x-(arr[i]%x))%x;
            int yMod = arr[i]%y;
            cnt += mp[{xMod,yMod}];
            mp[{arr[i]%x,arr[i]%y}]++;
        }

        cout<<cnt<<"\n";
    }

    return 0;
}
